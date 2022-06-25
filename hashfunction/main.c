#include <stdio.h>
#include <stdlib.h>

int codeofstring(char* s)
{
    //char c;
    int summa = 0;;
    while ((*s) != '\0')
    {
        summa += (int)(*s);
        s++;
    }
    return summa;

}

int main()
{
    //TASK 1
    char* str;
    printf("Input string: ");
    scanf("%s", str);
    printf("%d\n", codeofstring(str));

    return 0;
}
