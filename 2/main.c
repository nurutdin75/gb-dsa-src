#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ()
{
    setlocale(LC_ALL, "Rus");
    system("cls");
    printf("Привет, мир!\n");
    system("pause");
    return 0;
}
