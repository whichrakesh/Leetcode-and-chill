/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    let xor = 0;
    nums.forEach(n => xor = xor ^ n);
    return xor;
};