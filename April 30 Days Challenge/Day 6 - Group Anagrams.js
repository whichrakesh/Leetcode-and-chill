var sort = function(str){
    let a = [];
    for(let ch of str){
        a.push(ch);
    }
    a.sort();
    let st = "";
    for(let ch of a){
        st += ch;
    }
    return st;
}

/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    let strMap = {};
    strs.forEach(s => {
        if(!strMap[sort(s)]){
            strMap[sort(s)] = [];
        }
        strMap[sort(s)].push(s);
    })
    return Object.values(strMap);