int removeDuplicates(int* nums, int numsSize){
        int i = 0, j = 0;
        if(numsSize == 0) return 0;
        for(;j < numsSize;j++)
        {
            if(nums[i] != nums[j])
                nums[++i] = nums[j];
        }
        return i+1;
}
