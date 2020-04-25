/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function(nums, k) {
    let sums = nums.map(r => 0), count = 0;
    for(let i = 0; i < nums.length; i++){
        sums[i] = nums[i];
        if(sums[i] == k){
                count++;
            }
        for(let j = i+1; j<nums.length; j++){
              sums[j] = nums[j] + sums[j-1];
            if(sums[j] == k){
                count++;
            }
            
        }
    }
    return count;
};