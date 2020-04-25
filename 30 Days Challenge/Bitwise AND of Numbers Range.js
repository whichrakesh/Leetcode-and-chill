/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var rangeBitwiseAnd = function(m, n) {
    let b1 = getBinary(m);
    let b2 = getBinary(n);
    let val = 0, f1 = 0;
    if(b1.length == b2.length){
        for(let i = 0; i<b1.length; i++){
            if(b1[i] == b2[i] && !f1){
                val = val * 2 + b1[i];
            } else {
                f1 = 1;
                val = 2 * val;
            }
        }
    } 
    return val;
};

var getBinary = function(m){
    if(m == 0){
        return [0];
    } else if(m == 1){
        return [1];
    } 
    return [...getBinary(Math.floor(m/2)), m%2];
}