

void rotate(int* nums, int numsSize, int k){
    int temp;
    int i;
    while(k--)
    {
        temp = nums[numsSize-1];
        for(i = numsSize-1; i > 0; i--)
        {
            nums[i] = nums[i-1];
        }
        nums[0] = temp;
    }
}

