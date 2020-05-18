// https://leetcode.com/explore/interview/card/google/67/sql-2/472/
// Time Compexity: O(size of S)
// Space Complexity: O(size of S)
/**
 * @param {string} S
 * @param {number} K
 * @return {string}
 */
var licenseKeyFormatting = function(S, K) { // abc-df
    let s = S.replace(/-/g, '').toUpperCase();
    let rem = s.length % K;
    let str = s.substr(0, rem);
    for(let i=rem; i<s.length; i += K){
        str += (str.length > 0 ? '-': '') + s.substr(i, K);
    }
    return str;
};