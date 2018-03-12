# 第六章 堆排序
堆排序（heapsort）的时间复杂度为$O(n\lg n)$。堆排序具有空间原址性：任何时候都只需要常数个额外的元素空间存储临时数据。
## 6.1 堆
（二叉）堆是一个数组，它可以被看成一个近似的完全二叉树。表示堆的数组A包含两个属性：A.length给出数组元素的个数，A.heap-size表示有多少个堆元素存储在该数组中。树的根节点是A[1]。

二叉堆可以分为最大堆和最小堆。最大堆满足`A[PARENT(i)] >= A[i]`，最小堆则相反。在堆排序算法中，我们使用最大堆。最小堆常用于构造优先队列。

如果把堆看成一棵树，定义一个堆中结点的高度为该结点到叶结点最长简单路径上边的数目。堆的高度定义为根结点的高度。

## 6.2 维护堆的性质
MAX-HEAPIFY是用于维护最大堆性质的重要过程。
```
MAX-HEAPIFY(A, i)
  l = LEFT(i)
  r = RIGHT(i)
  if l <= A.heap-size and A[l] > A[i]
    largest = l
  else largest = i
  if r <= A.heap-size and A[r] > A[i]
    largest = r
  else largest = i
  if largest != i
    exchange A[i] with A[largest]
    MAX-HEAPIFY(A, largest)
```

## 6.3 建堆
```
BUILD-MAX-HEAP(A)
  A.heap-size = A.length
  for i = A.length / 2 downto 1
    MAX-HEAPIFY(A, i)
```
## 6.4 堆排序算法
因为数组中的最大元素总在根结点A[1]中，通过将其与A[n]互换，可以让其放在正确的位置，然后我们从堆中去除结点n，并调用MAX-HEAPIFY(A, 1)来维护最大堆的性质，从而构建一个新的最大堆。重复此过程，可以使所有数据有序。
```
HEAPSORT(A)
  BUILD-MAX-HEAP(A)
  for i = A.length downto 2
    exchage A[i] with A[1]
    A.heap-size = A.heap-size - 1
    MAX-HEAPIFY(A, 1)
```
## 6.5 优先队列
优先队列（priority queue）是一种用来维护由一组元素构成的集合S的数据结构，其中每一个元素都有一个相关的值，称为关键字（key）。一个最大优先队列支持以下操作：

    1. INSERT(S, x)：把元素插入到集合S中
    2. MAXIMUM(S)：返回S中具有最大键字的元素
    3. EXTRACT-MAX(S)：去掉并返回S中具有最大键字的元素
    4. INCREASE-KEY(S, x, k)：将元素x的关键字值增加到k，这里假设k的值不小于x的原关键字值

在用堆来实现优先队列时，需要在堆中的每个元素里存储对应的句柄（handle）。过程HEAP-MAXIMUM(A)如下：
```
HEAP-MAXIMUM(A)
  return A[1]
```
过程HEAP-EXTRACT-MAX实现EXTRACT-MAX操作。具体实现如下：
```
HEAP-EXTRACT-MAX(A)
  if A.heap-size < 1
    error "heap underflow"
  max = A[1]
  A[1] = A[A.heap-size]
  A.heap-size = A.heap-size - 1
  MAX-HEAPIFY(A, 1)
  return max
```
过程HEAP-INCREASE-KEY实现INCREASE-KEY操作
```
HEAP-INCREASE-KEY(A, i, key)
  if key < A[i]
    error "new key is smaller than current key"
  A[i] = key
  while i > 1 and A[PARENT(i)] < A[i]
    exchage A[i] with A[PARENT(i)]
    i = PARENT(i)
```
过程MAX-HEAP-INSERT实现INSERT操作
```
MAX-HEAP-INSERT(A, key)
  A.heap-size = A.heap-size + 1
  A[A.heap-size] = 0
  HEAP-INCREASE-KEY(A, A.heap-size, key)
```
