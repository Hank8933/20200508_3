#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c)
{
    int min = a;
    if (min > b) min = b;
    if (min > c) min = c;
    return min;
}

int minNum(char *a, char *b, int la, int lb)
{
    if (la == 0) return lb;
    if (lb == 0) return la;

    int ans;
    if (*(a + la - 1) == *(b + lb - 1))
        ans = minNum(a, b, la - 1, lb - 1);
    else
        ans = min(minNum(a, b, la - 1, lb - 1), minNum(a, b, la - 1, lb), minNum(a, b, la, lb - 1)) + 1;
    return ans;
}

int main()
{
    char a[21] = {0}, b[21] = {0};
    scanf("%s %s", a, b);
    printf("%d", minNum(a, b, strlen(a), strlen(b)));
    return 0;
}
