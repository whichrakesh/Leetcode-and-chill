/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    return search2(nums, target, 0, nums.length - 1);
};

var search2 = function(nums, target, start, end) {
    if(nums[start] == target){
        return start;
    }
    if(nums[end] == target){
        return end;
    }
    if(start >= end){
        return -1;
    }
    let midPoint = Math.floor((start + end) / 2);
    if(nums[midPoint] == target){
        return midPoint;
    }
    if((nums[start] < nums[midPoint] && nums[start] < target && target < nums[midPoint]) || 
       (nums[start] > nums[midPoint] && (nums[start] < target || target < nums[midPoint]))){
        return search2(nums, target, start, midPoint - 1);
    }
    else if((nums[midPoint] < nums[end] && nums[midPoint] < target && target < nums[end]) || 
       (nums[midPoint] > nums[end] && (nums[midPoint] < target || target < nums[end]))){
        return search2(nums, target, midPoint + 1, end);
    }
    return -1;    
};
    
    