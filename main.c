#include <stdio.h>
#include <stdlib.h>

void bin(int); // TASK 1
int exponenta(int, int); // TASK 2
int evenodd(int, int); // TASK 3

int main()
{
    //TASK 1
    int a;
    printf("Enter number: ");
    scanf("%d",&a);
    printf("%d = ", a);
    bin(a);

    //TASK 2
    int x, y;
    printf("\nEnter base: ");
    scanf("%d",&x);
    printf("Enter degree: ");
    scanf("%d",&y);
    printf("%d in degree %d = %d", x, y, exponenta(x,y));

    //TASK 3
    int base, degree;
    printf("\nEnter base: ");
    scanf("%d",&base);
    printf("Enter degree: ");
    scanf("%d",&degree);
    printf("%d in degree %d = %d", base, degree, evenodd(base, degree));

    return 0;
}

void bin(int x)
{
    if ((x == 1) || (x ==0))
        printf("%d", x);
    else {
        bin(x/2);
        printf("%d", (x - ((x/2) << 1)));
    }
}
int exponenta(int x, int y)
{
    if (y == 1)
        return x;
    else return (x * exponenta(x, y - 1));
}
int evenodd(int a, int b)
{
    if (b == 0)
        return 1;
    else if (b == 1)
             return a;
         else if (b % 2 == 0)
                  return evenodd(a * a, b / 2);
              else
                  return a * evenodd(a, b - 1);
}
