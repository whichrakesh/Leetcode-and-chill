/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * function BinaryMatrix() {
 *     @param {integer} x, y
 *     @return {integer}
 *     this.get = function(x, y) {
 *         ...
 *     };
 *
 *     @return {[integer, integer]}
 *     this.dimensions = function() {
 *         ...
 *     };
 * };
 */

/**
 * @param {BinaryMatrix} binaryMatrix
 * @return {number}
 */
var leftMostColumnWithOne = function(binaryMatrix) {
    let dim = binaryMatrix.dimensions();
    let j=dim[1]-1, ans = -1;
    for(let i=0; i < dim[0] && j >= 0; ){
        if(binaryMatrix.get(i, j) == 0){
            i++;
        } else {
            ans = j;
            j--;
        }
    }
    return ans;
};