

void rotate(int* nums, int numsSize, int k){
    int i,j;
    k = k % numsSize;
    for(i = 0; i < (numsSize - k)/2; i++)
    {
        int temp = nums[i];
        nums[i] = nums[numsSize - k - i - 1];
        nums[numsSize - k - i - 1] = temp;
    }
    for(j = 0, i = numsSize - k; i < numsSize - k + (k/2); i++)
    {
        int temp = nums[i];
        nums[i] = nums[numsSize-1-j];
        nums[numsSize-1-j] = temp; 
        j++;
    }
    for(i = 0; i < numsSize/2; i++)
    {
        int temp = nums[i];
        nums[i] = nums[numsSize-i-1];
        nums[numsSize-i-1] = temp;
    }
    return nums;
}

