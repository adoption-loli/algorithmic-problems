int cmp(const void *a, const void *b)
{
    return (*(int*)a-*(int*)b);
}

int singleNumber(int* nums, int numsSize){
    qsort(nums, numsSize,sizeof(int),cmp);
    int i;
    for( i = 1; i <= numsSize; i+=2)
    {
        if(i>=numsSize || nums[i-1]!=nums[i])
            return nums[i-1];   
    }
    return 0;
}
