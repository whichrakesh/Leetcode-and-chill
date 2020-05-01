/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxLength = function(nums) {
    let k = 0, maxLength = 0, map = {0: -1};
    nums.forEach((n, i) => {
        if(!map.hasOwnProperty(n == 0 ? ++k : --k)){
            map[k] = i;
        } else {
            maxLength = Math.max(maxLength, i - map[k]);
        }
    })
    return maxLength;
};