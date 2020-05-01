/**
 * @param {string} s
 * @param {number[][]} shift
 * @return {string}
 */
var stringShift = function(s, shift) {
    let k = 0;
    shift.forEach(sh => { k += (sh[0] == 0 ? 1 : -1) * sh[1]});
    if(k < 0){
        k = k * -1;
        k = k % s.length;
        let l = s.substr(s.length - k, k);
        let r = s.substr(0, s.length - k);    
        return l + r;
    } else {
        k = k % s.length;
        let l = s.substr(k, s.length - k);
        let r = s.substr(0, k);    
        return l + r;
    }
};