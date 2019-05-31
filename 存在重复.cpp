int singleNumber(int* nums, int numsSize){
    int i,temp = 0;
    for(i = 0; i < numsSize; i++)
        temp = temp ^ nums[i];
    return temp;
}