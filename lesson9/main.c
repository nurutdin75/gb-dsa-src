#include <stdio.h>
#include <stdlib.h>


#define size 10
#define sizeofstack 1000
#define true 1 == 1
#define false 1 != 1

typedef int T;
typedef int boolean;
int cursor = -1;
T Stack[sizeofstack];

typedef struct {
    int pr;
    int dat;
} Node;
Node* arr[size];
int head;
int tail;
int items;

void init() {
    for(int i = 0; i < size; ++i)
        arr[i] = NULL;
    head = 0;
    tail = 0;
    items = 0;
}
void ins(int pr, int dat) {
    if (items == size) {
        printf("%s \n", "Queue is full");
    } else {
          Node* node = (Node*)malloc(sizeof(Node));
          node->pr = pr;
          node->dat = dat;
          arr[tail++ % size] = node;
          items++;
      }
}
Node* rm() {
    int idx = 0;
    int i = 0;
    int k = 0;
    int flag = 0;
    if (items == 0)
        return NULL;
    else {
        idx = head % size;
        flag = head;
        for(i = head + 1; i < tail; ++i) {
            k = i % size;
            if (arr[idx]->pr < arr[k]->pr) {
                idx = k;
                flag  = i;
            }
        }
    }
    Node* tmp = arr[idx];
    flag--;
    while (flag >= head) {
        arr[idx] = arr[flag % size];
        idx = flag % size;
        flag--;
    }
    items--;
    arr[++flag % size] = NULL;
    head++;
    return tmp;
}

void printQueue() {
    printf("[ ");
    for(int i = 0; i < size; ++i) {
        if (arr[i] == NULL)
            printf("[*, *] ");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}
boolean pushStack(T data) {
    if (cursor < sizeofstack) {
        Stack[++cursor] = data;
        return true;
    } else {
          printf("%s \n", "Stack overflow");
          return false;
      }
}
T popStack() {
    if (cursor != -1) {
        return Stack[cursor--];
    } else {
          printf("%s \n", "Stack is empty");
          return -1;
      }
}

boolean dectobin (int number, char* result) {
    if (number <= 0)
        return false;
    while(number >= 1) {
        pushStack(number % 2);
        number /= 2;
    }
    int count = cursor;
    for(int i = 0; i <= count; ++i) {
        strcat(result, (popStack()) ? "1" : "0");
    }
    strcat(result, "\0");
    return true;
}
int main()
{   // TASK 1
    init();
    ins(2, 90);
    ins(5, 60);
    ins(1, 12);
    ins(8, 50);
    ins(3, 42);
    ins(2, 15);
    ins(6, 25);
    ins(4, 12);
    ins(1, 35);
    ins(9, 78);
    printQueue();

    for(int i = 0; i < 3; ++i) {
        Node* nodemain = rm();
        printf("pr=%d, dat=%d \n", nodemain->pr, nodemain->dat);

    }
    printQueue();

    ins(9, 99);
    ins(6, 82);
    printQueue();

    for(int i = 0; i < 5; ++i) {
        Node* nodemain = rm();
        printf("pr=%d, dat=%d \n", nodemain->pr, nodemain->dat);
    }
    printQueue();
    // TASK 2
    char* str;
    dectobin(48, str);
    printf("%s", str);
    return 0;
}
