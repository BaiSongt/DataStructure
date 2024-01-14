
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

#include "DynamicArray.h"

DynamicArray *init() ///< 初始化
{
  DynamicArray *my_array = (DynamicArray *)malloc(sizeof(DynamicArray));
  my_array->size = 0;
  my_array->capacity = 20;
  my_array->pAddr = (int *)malloc(sizeof(int) * my_array->capacity);

  return my_array;
}

void push_back(DynamicArray *arr, int val) ///< 末端插入
{
  if (arr == NULL)
    return;
  // 判断空间是否足够
  if (arr->size == arr->capacity)
  {
    // 扩展空间
    // 1 申请一块更大空间  新空间是旧空间的 2 倍
    int *newSpace = (int *)malloc(sizeof(int) * arr->capacity * 2);
    // 2 拷贝数据到新空间
    memcpy(newSpace, arr->pAddr, arr->capacity * sizeof(int));
    // 3 释放旧空间的内容
    free(arr->pAddr);

    // 更新arr
    arr->capacity = arr->capacity * 2;
    arr->pAddr = newSpace;
  }

  // 插入新元素 在末尾
  arr->pAddr[arr->size] = val;
  arr->size++;
}

void remove(DynamicArray *arr, int pos) ///< 按位置删除
{
  if (arr == NULL)
    return;

  // 判断位置是否有效
  if (pos < 0 || pos >= arr->size)
    return;

  // delete
  for (int i = pos; i < arr->size - 1; i++)
    arr->pAddr[i] = arr->pAddr[i + 1];

  arr->size--;
}

// 删除第一个出现的value
void remove_by_value(DynamicArray *arr, int value) ///< 按内容删除
{
  if (arr == NULL)
    return;
  // 寻找值的位置
  remove(arr, find(arr, value));
}

int find(DynamicArray *arr, int value) ///< 查找
{
  if (arr == NULL)
    return -1;
  // 寻找值的位置
  int poss = 0;
  for (int pos = 0; pos < arr->size; pos++)
  {
    if (arr->pAddr[pos] == value)
    {
      poss = pos;
      break;
    }
  }
  return poss;
}

void print(DynamicArray *arr) ///< 打印
{
  if (arr == NULL)
    return;
  for (int i = 0; i < arr->size; i++)
  {
    cout << i << "\t" << arr->pAddr[i] << endl;
  }
  cout << endl;
}

void free_space(DynamicArray *arr) ///< 释放内存
{
  if (arr == NULL)
    return;
  if (arr->pAddr != NULL)
  {
    free(arr->pAddr);
  }
  free(arr);
}

void clear(DynamicArray *arr) ///< 清空清空
{
  if (arr == NULL)
    return;
  arr->size = 0;
}

int size(DynamicArray *arr) ///< 获得当前大小
{
  if (arr == NULL)
    return -1;
  return arr->size;
}

int capacity(DynamicArray *arr) ///< 获得容量获得容量
{
  if (arr == NULL)
    return -1;
  return arr->capacity;
}

int at(DynamicArray *arr, int pos) ///< 获得指定位置的元素获得指定位置的元素
{
  if (pos <= arr->size - 1)
    return arr->pAddr[pos];
  else
    cout << "索引超出数组大小" << endl;
  return 0;
}
