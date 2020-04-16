/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    if(nums.length == 0){
        return 0;
    }
    let maxSum = nums[0], maxSumTillLast = nums[0];
    for(let i=1; i<nums.length; i++){
        if(maxSumTillLast < 0){
            maxSumTillLast = nums[i];
        } else {
            maxSumTillLast = maxSumTillLast + nums[i];
        }
        maxSum = Math.max(maxSumTillLast, maxSum); 
    }
    return maxSum;
};