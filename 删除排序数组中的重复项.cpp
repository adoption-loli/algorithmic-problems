#include<stdio.h>

int main()
{
    int nums[20] = {0,0,1,1,1,2,2,3,3,4};
    int i = 0, j = 0, flag = 0, k = 1;
    for(i = 1;i < 10; i++)
    {
        for(j = 0; j < k; j++)
        {
            if(nums[j] == nums[i])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            flag = 0;
        }
        else
        {
            nums[k++] = nums[i];
        }
    }
    return 0;
}