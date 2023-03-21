#include "sample.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** allocateMatrix2d(const int rows, const int cols);

enum { N = 10 };

void test(int argc, char argv[]) {
  const char* name = "John";

  uint64_t x = 2;
  printf("hello, %d %s \n", (int)x, name);

  int arr1[N] = {33, 44, 0};
  int arr2[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr3[N] = {0};

  memcpy(arr3, arr2, sizeof(arr3));

  for (int i = 0; i < N; ++i) printf("%2d ", arr1[i]);
  printf("\n");
  for (int i = 0; i < N; ++i) printf("%2d ", arr2[i]);
  printf("\n");
  for (int i = 0; i < N; ++i) printf("%2d ", arr3[i]);
  printf("\n");

  // & взятие адреса, * разыменование, int* указатель не int
  int i = 10;
  int* i_ptr = &i;
  int** i_ptr_ptr = &i_ptr;
  printf("%d - %d - %d \n", i, *i_ptr, **i_ptr_ptr);
  *i_ptr = 42;
  printf("%d - %d - %d \n", i, *i_ptr, **i_ptr_ptr);
  **i_ptr_ptr = 3;
  printf("%d - %d - %d \n", i, *i_ptr, **i_ptr_ptr);

  int* p = arr2 + 5;
  printf("%2d \n", p[-1]);

  char letter = 'x';
  int num = 42;
  void* pointer_without_type;
  pointer_without_type = &letter;
  printf("%c\n", *(char*)pointer_without_type);
  pointer_without_type = &num;
  printf("%d\n", *(int*)pointer_without_type);
}

void allocationTest() {
  uint64_t n;
  printf("Enter size of array to create: ");
  scanf("%lld", &n);
  char* a = (char*)malloc(n);

  // int* arr = (int*) calloc(n, sizeof(int));// n * size and fill with 0;

  if (NULL == a) {
    printf("OS didn't allocate %lld bytes\n", n);
  } else {
    printf("Array with size %lld bytes succecefully created\n", n);
  }
  system("pause");

  free(a);

  printf("Array released\n");
}

void dynamicArray2dTest() {
  const int rows = 3, cols = 5;

  // allocate
  int** arr = allocateMatrix2d(rows, cols);
  if (NULL == arr) {
    printf("allocateMatrix2d return null\n");
    return;
  }

  // fill
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      arr[row][col] = row * cols + col + 1;
    }
  }
  // print
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      printf("%3d", arr[row][col]);
    }
    printf("\n");
  }

  // free
  free(arr);
}

// PRIVATE

int** allocateMatrix2d(const int rows, const int cols) {
  printf("%d rows, %d cols\n", rows, cols);
  int** p = (int**)malloc(rows * sizeof(int*) + rows * cols * sizeof(int));
  if (NULL == p) {
    printf("OS didn't allocate memory\n");
    return NULL;
  }
  char* offset = (char*)p + rows * sizeof(int*);
  for (int row = 0; row < rows; ++row) {
    p[row] = (int*)(offset + row * cols * sizeof(int));
  }
  return p;
}