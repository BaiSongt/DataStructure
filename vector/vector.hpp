typedef int Rank;          // 秩
#define DEFAULT_CAPACITY 3 // 默认最大初始容量（实际应用中可讴置为更大）

template <typename T>
class Vector
{
protected:
  Rank _size;    ///< 规模
  int _capacity; ///< 容量
  T *_elem;      ///< 数据区

  void copyFrom(T const *A, Rank lo, Rank hi);
  void expand();
  void shrink();
  bool bubble(Rank lo, Rank hi);
  void bubbleSort(Rank lo, Rank hi);
  Rank max(Rank lo, Rank hi);
  void selectionSort(Rank lo, Rank hi);
  void merge(Rank lo, Rank mi, Rank hi);
  void mergeSort(Rank lo, Rank hi);
  Rank partition(Rank lo, Rank hi);
  void quickSort(Rank lo, Rank hi);
  void heapSort(Rank lo, Rank hi);

public:
  /// constructor

  /// @brief 容量为c、规模为s、所有元素初始为v
  Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)
  {
    _elem = new T[_capacity = c];
    for (_size = 0; _size < s; _elem[_size++] = v)
      ;
  }

  /// @brief 整体数组复制
  Vector(T const *A, Rank n) { copyFrom(A, 0, n); }

  /// @brief 区间
  Vector(T const *A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }

  /// @brief 向量整体复制
  Vector(Vector<T> const &V) { copyFrom(V._elem, 0, V._size); }

  /// @brief 向量区间复制
  Vector(Vector<T> const &V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); }

  /// @brief 幅值构造
  Vector<T> &operator=(Vector<T> const &V)
  {
    if (_elem)
      delete[] _elem;              // 释放原有内容
    copyFrom(V._elem, 0, V._size); // 整体复制
    return *this;
  }

  ~Vector(){delete[] _elem;}

  int size(){ return _size;}
  int capacity(){ return _capacity;}
};

template <typename T>
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi)
{
  // 分配空间
  _elem = new T[_capacity = 2 * (hi - lo)];
  _size = 0;
  // 遍历复制至新空间
  while (lo < hi)
    _elem[_size++] = A[lo++];
}

/// @brief 向量空间不足时扩容
/// @tparam T
template <typename T>
void Vector<T>::expand()
{
  if (_size < _capacity)
    return;
  if (_capacity < DEFAULT_CAPACITY)
    _capacity = DEFAULT_CAPACITY; // 不低于最小容量

  T *oldElem = _elem;
  _elem = new T[_capacity <<= 1]; // 容量加倍 位运算 << 1 <=> *2
  for (int i = 0; i < _size; i++)
    _elem[i] = oldElem[i]; // 复制内容

  delete[] oldElem; // 释放原来的空间
}

template <typename T>
void Vector<T>::shrink() {}

template <typename T>
bool Vector<T>::bubble(Rank lo, Rank hi) {}

template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {}

template <typename T>
Rank Vector<T>::max(Rank lo, Rank hi) {}

template <typename T>
void Vector<T>::selectionSort(Rank lo, Rank hi) {}

template <typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi) {}

template <typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi) {}

template <typename T>
Rank Vector<T>::partition(Rank lo, Rank hi) {}

template <typename T>
void Vector<T>::quickSort(Rank lo, Rank hi) {}

template <typename T>
void Vector<T>::heapSort(Rank lo, Rank hi) {}

