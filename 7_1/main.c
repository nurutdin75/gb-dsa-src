#include <stdio.h>
#include <stdlib.h>

void fillArrRandom(int*, const int);
void printArr(int*, const int);
void swap(int *, int *);
void sortinsert(int*, int, int);
void quicksort(int* arr, int first, int last);

int main()
{
    const int size = 30;
    int arr[size];
    fillArrRandom(arr, size);
    printArr(arr, size);
    quicksort(arr, 0, size-1);
    printArr(arr, size);
    return 0;
}
void fillArrRandom(int* a, const int size)
{
    for(int i = 0; i < size; ++i)
        a[i] = rand() % 100;
}
void printArr(int* a, const int size)
{
    for(int i = 0; i < size; ++i)
        printf("%d ", a[i]);
    printf("\n\n");
};
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void sortinsert(int* a, int firstsort, int lastsort)
{
    int temp, position;
    for(int i = firstsort + 1; i <= lastsort; i++) {
        temp = a[i];
        position = i - 1;
        while (position >= 0 && a[position] > temp){
            a[position + 1] = a[position];
            position--;
        }
        a[position + 1] = temp;
    }
}
void quicksort(int* arr, int first, int last)
{
    int i = first;
    int j = last;
    if ((last - first + 1) <= 10)
        sortinsert(arr, first, last);
    else {
        int mid = (arr[first] + arr[(first + last)/2] + arr[last])/3;
        int pokazatel = (first + last)/2;
        int min = abs(mid - arr[pokazatel]);
        for(int count = first; count <= last; count++)
            if (abs(mid - arr[count]) < min)
            {
                min = arr[count];
                pokazatel = count;
            }
        swap(&arr[(first + last)/2], &arr[pokazatel]);
        mid = arr[(first + last)/2];
        do {
            while (arr[i] < mid) i++;
            while (arr[j] > mid) j--;
            if (i < j) {
                swap(&arr[i], &arr[j]);
                i++;
                j--;
            }
        } while (i < j);
        if (i + 1 < last) quicksort(arr, i, last);
        if (j - 1 > first) quicksort(arr, first, j);
    }
}
