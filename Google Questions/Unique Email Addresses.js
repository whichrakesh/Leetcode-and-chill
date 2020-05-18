// https://leetcode.com/explore/interview/card/google/67/sql-2/3044/
// Time Complexity: O(n * sizeof(email))
/**
 * @param {string[]} emails
 * @return {number}
 */
var numUniqueEmails = function(emails) {
    let usernameMap = {};
    emails.forEach(e => {
        let index = e.indexOf('@');
        if(e.indexOf('+') > -1){
            index = e.indexOf('+');
        }
       usernameMap[e.substr(0, index).replace(/\./g, '') + e.substr(e.indexOf('@'))] = 1; 
    });
    return Object.keys(usernameMap).length;
};