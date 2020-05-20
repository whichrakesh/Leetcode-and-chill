/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let p1 = 0, p2 = height.length - 1;
    let maxArea = 0;
    while(p1 != p2){
        if(height[p1] < height[p2]){
            maxArea = Math.max((p2 - p1) * height[p1], maxArea); 
            p1++;
        } else {
            maxArea = Math.max((p2 - p1) * height[p2], maxArea); 
            p2--;
        }
    }
    return maxArea;
};