#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** CreateandInitArray(int, int);
void printArrayTwo(int**, const int, const int);
void deleteArray(int**, const int);
void printArrayOne(int*, const int);
void printArrayOne2(double*, const int);
void calculation(int*, double*, const int);
void sortTwoDimension();
void algorithmTrabba();

int main()
{
    sortTwoDimension();
    algorithmTrabba();

    system("PAUSE");
    return 0;
}
void sortTwoDimension()
{
    const int sizeY = 3;
    const int sizeX = 9;
    int** pArray = CreateandInitArray(sizeY, sizeX);
    printArrayTwo(pArray, sizeY, sizeX);
    for (int i = 0; i < sizeY; ++i)
        for (int j = 0; j < sizeX; ++j) {
            int min = pArray[i][j];
            int imin = i;
            int jmin = j;
            for (int i1 = i; i1 < sizeY; ++i1) {
                int j1 = ((i1 == i) ? j + 1 : 0);
                for (; j1 < sizeX; ++j1) {
                    if (min > pArray[i1][j1]) {
                        min = pArray[i1][j1];
                        imin = i1;
                        jmin = j1;
                    }
                }
            }
            if (min != pArray[i][j]) {
                int temp = pArray[i][j];
                pArray[i][j] = pArray[imin][jmin];
                pArray[imin][jmin] = temp;
            }
        }
    printArrayTwo(pArray, sizeY, sizeX);
    deleteArray(pArray, sizeY);
}
void algorithmTrabba()
{
    const int marka = 400;
    const int size = 11;
    int array2[size];
    for (int i = 0; i < size; ++i) {
        printf("Input %i number: ", i + 1);
        scanf("%d", &array2[i]);
    }
    int divider = size / 2;
    for (int i = 0; i < divider; ++i) {
        int temp = array2[i];
        array2[i] = array2[size - 1 - i];
        array2[size - 1 - i] = temp;
    }
    printArrayOne(array2, size);
    double b[size];
    calculation(array2, b, size);
    for (int i = 0; i < size; ++i)
        if (b[i] > marka)
            printf("Calculation for %d member of sequence is more than %d\n", i + 1, marka);
    printArrayOne2(b, size);
}
int** CreateandInitArray(const int y, const int x)
{
    int** p = (int**)malloc(y * sizeof(int*));
    for (int i = 0; i < y; ++i)
        p[i] = (int*)malloc(x * sizeof(int));
    for (int i = 0; i < y; ++i)
        for (int j = 0; j < x; ++j)
            p[i][j] = rand() % 100;
    return p;
}
void printArrayTwo(int** arr, const int y, const int x)
{
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j)
            printf("%3d", arr[i][j]);
        printf("\n");
    }
    printf("\n\n");
}
void deleteArray(int** arr, const int size)
{
    for (int i = 0; i < size; ++i)
        free(arr[i]);
    free(arr);
}
void printArrayOne(int* a, const int size)
{
    printf("\n");
    for (int i = 0; i < size; ++i)
        printf("%d%s", a[i], " ");
    printf("\n");
}
void printArrayOne2(double* bcalc, const int size)
{
    printf("\n");
    for (int i = 0; i < size; ++i)
        printf("%.2f%s", bcalc[i], " ");
    printf("\n");
}
void calculation(int* a, double* calc, const int size)
{
    for (int i = 0; i < size; ++i) {
        calc[i] = sqrt(fabs(a[i])) + 5 * pow(a[i], 3);
    }
    printf("\n");
}
