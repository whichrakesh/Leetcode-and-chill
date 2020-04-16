/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let index2 = 0;
    for(let i=0; i<nums.length; i++){
        if(nums[i] != 0){
           nums[index2] = nums[i];
            index2++;
        }
    }
    for(let i=index2; i<nums.length; i++){
        nums[i] = 0;
    }
};