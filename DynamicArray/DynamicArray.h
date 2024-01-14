#ifndef DynamicArray_h
#define DynamicArray_h

// 动态增长内存，策略，将存放的数据内容放在堆上
// 动态数组 申请内存 拷贝数据 释放内存
// 容量 capacity
// 大小 size

typedef struct DynamicArray
{
  int *pAddr;   ///< 存放数据的地址
  int size;     ///< 元素个数
  int capacity; ///< 最大容量
} DynamicArray;

// 操作函数
DynamicArray *init();                               ///< 初始化
void push_back(DynamicArray *arr, int val);         ///< 末端插入
void remove(DynamicArray *arr, int pos);            ///< 按位置删除
void remove_by_value(DynamicArray *arr, int value); ///< 按内容删除
int find(DynamicArray *arr, int value);             ///< 查找
void print(DynamicArray *arr);                      ///< 打印
void free_space(DynamicArray *arr);                 ///< 释放内存
void clear(DynamicArray *arr);                      ///< 清空
int size(DynamicArray *arr);                        ///< 获得当前大小
int capacity(DynamicArray *arr);                    ///< 获得容量
int at(DynamicArray *arr, int);                     ///< 获得指定位置的元素

#endif /* DynamicArray_hpp */
