/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxLength = function(nums) {
    let k = 0, maxLength = 0;
    let map = {};
    map[0] = -1;
    for(let i = 0; i < nums.length; i++){
        if(nums[i] == 0){
            k++;
        } else {
            k--;
        }
        if(!map.hasOwnProperty(k)){
            map[k] = i;
        } else {
            maxLength = Math.max(maxLength, i - map[k]);
        }
    }
    return maxLength;
};