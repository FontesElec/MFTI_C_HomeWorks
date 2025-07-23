#include <stdio.h>
int nums[5];
int min;
int main(void){
    scanf("%d %d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4]);
    min = nums[0];
    for(int i = 1; i < sizeof(nums) / 4; i++){
        if(min > nums[i]){
            min = nums[i];
        } 
    }
    printf("%d\n", min);
    return 0;
}