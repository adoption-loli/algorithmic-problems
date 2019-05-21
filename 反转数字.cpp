#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
  *注意:
  *假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
  *示例 1:
  *输入: 123
  *输出: 321

  *示例 2:
  *输入: -123
  *输出: -321

  *示例 3:
  *输入: 120
  *输出: 21
  */

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
