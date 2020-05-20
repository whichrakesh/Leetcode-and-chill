/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let charMap = {}, maxLength = 0, curLength = 0;
    for(let i=0; i<s.length; i++){
        if(charMap[s[i]] == null || charMap[s[i]] < i - curLength){
            charMap[s[i]] = i;
            curLength++;
        } else {
            curLength = i - charMap[s[i]];
            charMap[s[i]] = i;
        }
        maxLength = Math.max(maxLength, curLength);
    }
    return maxLength;
};
