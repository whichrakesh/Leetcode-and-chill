/**
 * @param {number[]} arr
 * @return {number}
 */
var countElements = function(arr) {
    let m = {};
    arr.forEach(i => m[i] = true);
    let count = 0;
    arr.forEach(i => {
        if(m[i+1]){
            count++;
        }
    })
    return count;
};