#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**********
I      1
V      5
X      10
L      50
C      100
D      500
M      1000
************/

int fun(char x[20])
{
    int num[11],j = 1,i = 0,sum = 0;
    int len = strlen(x);
    num[0] = 0;
    for(int i = 0; i < len; i++)
    {
        if(x[i] == 'I') num[j] = 1;
        else if(x[i] == 'V') num[j] = 5;
        else if(x[i] == 'X') num[j] = 10;
        else if(x[i] == 'L') num[j] = 50;
        else if(x[i] == 'C') num[j] = 100;
        else if(x[i] == 'D') num[j] = 500;
        else if(x[i] == 'M') num[j] = 1000;
        if(num[j] > num[j-1])
        {
            num[j-1] = num[j] - num[j-1];
            num[j] = 0;
        }
        else j++;
    }
    for(i = 0; i < j; i++)
        sum += num[i];
    return sum;
}

int main()
{
    char a[20];
    scanf("%s",a);
    printf("%d",fun(a));
    return 0;
}
