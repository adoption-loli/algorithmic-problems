#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fun()
{
    int x;
    scanf("%d",&x);
    int ans = 0, now = 0;
    while(x)
    {
        now = x%10;
        x/=10;
        if(ans > 214748364 || (ans == 214748364 && now > 7))
            return 0;
        if(ans < -214748364 || (ans == -214748364 && now < -8))
            return 0;
        ans = ans*10 + now;
    }
    return ans;
}

int main()
{
    printf("%d",fun());
    return 0;
}
