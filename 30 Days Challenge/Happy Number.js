var getDigits = function(n) {
    let digits = [];
    while(n > 0){
        digits.push(n%10);
        n = Math.floor(n/10);
    }
    return digits;
};
/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
    let sum = n;
    let sumMap = {};
    while(true){
        sumMap[sum] = true;
        let digits = getDigits(sum);
        let sum1 = 0;
        for(let d of digits){
            sum1 += d * d;
        }
        sum = sum1;
        if(sum == 1){
            return true;
        }
        if(sumMap[sum]){
            return false;
        }
    }
};