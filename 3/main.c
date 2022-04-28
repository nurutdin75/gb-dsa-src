#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[1000] = {2, 3};
    int capacity = 2;
    for (int i = 4; i <= 1000; ++i) {
        int isSimple = 1;
        for (int k = 0; k < capacity; ++k) {
            if (i % arr[k] == 0) {
                isSimple = 0;
                break;
            }
        }
        if (isSimple)
            arr[capacity++] = i;
    }
    for (int k = 0; k < capacity; ++k) {
        printf("%d ", arr[k]);
        if (((k + 1) % 20) == 0)
            printf("\n");
    }
    return 0;
}
