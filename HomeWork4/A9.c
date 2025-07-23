#include <stdio.h>
int nums[5];
int max = 0;
int main(void){
    scanf("%d %d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4]);
    for(int i = 0; i < sizeof(nums) / 4; i++){
        if(max < nums[i]){
            max = nums[i];
        } 
    }
    printf("%d", max);
    return 0;
}