#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*FPTR)(int, int);

int add(int, int);
int sub(int, int);
int evaluate(char, int, int);
FPTR select(char);

FPTR select(char opcode)
{

    switch (opcode)
    {
    case '+':
        return add;
    case '-':
        return sub;
    }
}
int evaluate(char opcode, int n1, int n2)
{
    FPTR func = select(opcode);
    return func(n1, n2);
}
int main()
{

    int a = evaluate('+', 5, 6);
    int b = evaluate('-', 5, 6);
    printf("%d %d\n", a, b);
    return 0;
}
int add(int n1, int n2)
{
    return n1 + n2;
}
int sub(int n1, int n2)
{
    return n1 - n2;
}
// int arr[3][2] = {{10, 20}, {30, 40}, {50, 60}};
// int *p = *arr;
// printf("*(*arr + 0):%d\n", *(*arr + 0));
// printf("*(*arr + 1):%d\n", *(*arr + 1));
// printf("*(*(arr + 1) + 0):%d\n", *(*(arr + 1) + 0));
// printf("*(*(arr + 1) + 1):%d\n", *(*(arr + 1) + 1));
// printf("*(*(arr + 1) + 1):%d\n", *(*(arr + 2) + 0));
// printf("*(*(arr + 1) + 1):%d\n", *(*(arr + 2) + 1));
