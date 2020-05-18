// https://leetcode.com/explore/interview/card/google/67/sql-2/3046/
// Time Complexity: O(n)
// Space Complexity: O(1)

/**
 * @param {number[]} tree
 * @return {number}
 */
var totalFruit = function(tree) {
    let valPos = 0, lastVal = -1, lastValPos = -1, valsArr = [], maxLength = 0;
    for(let i=0; i<tree.length; i++){
        let val = tree[i];
        if(val != lastVal){
            if(valsArr.indexOf(val) == -1){
                lastValPos = valPos;
                if(valsArr.length < 2){
                    valsArr.push(val);
                } else {
                    let index = 1 - valsArr.indexOf(lastVal);
                    valsArr[index] = val;
                }
            }
            valPos = i;
            lastVal = val;
        }
        maxLength = Math.max(maxLength, i-lastValPos+1);
    }
    
    return maxLength;
};