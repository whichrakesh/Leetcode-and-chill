// https://leetcode.com/explore/interview/card/google/62/recursion-4/370/

/**
 * @param {string[]} words
 * @return {string[][]}
 */
var wordSquares = function(words) {
    let wordMap = {};
    for(let word of words){
        for(let i in word){
            let substr = word.substr(0, i);
            if(!wordMap.hasOwnProperty(substr)){
                wordMap[substr] = [];
            }
            wordMap[substr].push(word);
        }
    }
    
    let squares = [];
    for(let word of words){
        squares = [...squares, ...findSquares(wordMap, [word], word.length)];
    }
    return squares;
};

var findSquares = function(wordsMap, curSquare, wordLength) {
    let i = curSquare.length;
    if(i >= wordLength){
        return [curSquare];
    }
    let nextWordStart = curSquare.map(w => w[i]).join('');
    
    if(wordsMap.hasOwnProperty(nextWordStart)){
        let squares = [];
        for(let word of wordsMap[nextWordStart]){
            //if(curSquare.indexOf(word) == -1){
                squares = [...squares, ...findSquares(wordsMap, [...curSquare, word], wordLength)];   
            //}
        }
        return squares;
    }
    return [];
}