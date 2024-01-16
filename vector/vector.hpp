typedef int Rank;          // 秩
#define DEFAULT_CAPACITY 3 // 默认最大初始容量（实际应用中可讴置为更大）

template <typename T>
class Vector
{
protected:
  Rank _size;    ///< 规模
  int _capacity; ///< 容量
  T *_elem;      ///< 数据区

  void copyFrom(T const *A, Rand lo, Rank hi);
  void expand();
  void shrink();
  bool bubble(Rank lo, Rnak hi);
  void bubbleSort(Rank lo, Rank hi);
  Rank max(Rank lo, Rank hi);
  void selectionSort(Rand lo, Rnak hi);
  void merge(Rand lo, Rank mi, Rnak hi);
  void mergeSort(Rand lo, Rnak hi);
  Rank partition(Rand lo, Rnak hi);
  void quickSort(Rand lo, Rnak hi);
  void heapSort(Rand lo, Rnak hi);

public:

  /// 容量为c、觃模为s、所有元素刜始为v
  Vector(int c = DEFAULT_CAPACITY, int s = 0; T v = 0)
  {
    _elem = new T[_cacpcity = c];
    for (_size = 0; _size < s; _elem[_size++] = v)
      ;
  }

  ~Vector();
};
