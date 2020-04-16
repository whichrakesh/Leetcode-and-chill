/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    let output = nums.map(n => 0);
    output[0] = nums[0];
    for(let i=1; i<nums.length; i++){
        output[i] = output[i-1] * nums[i];
    }
    for(let i=nums.length-2; i>=0; i--){
        nums[i] = nums[i+1] * nums[i];
    }
    
    output[nums.length - 1] = output[nums.length - 2];
    for(let i=nums.length - 2; i > 0; i--){
        output[i] = output[i-1] * nums[i+1];
    }
    output[0] = nums[1];
    
    return output;
};