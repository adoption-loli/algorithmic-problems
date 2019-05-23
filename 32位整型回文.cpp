#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//不使用字符串判断回文32位整型。

bool fun(int x)
{
    if(x < 0)
        return false;
    long long num = 0;
    int y = x;
    while(x)
    {
        num = num*10 + x%10;
        x/=10;
    }
    if(y == num) return true;
    else return false;
}

int main()
{
    int a;
    scanf("%d",&a);
    printf("%d",fun(a));
    return 0;
}
