/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {

    var paths = grid.map(r => r.map(v => -1));
    paths[grid.length - 1][grid[0].length - 1] = grid[grid.length - 1][grid[0].length - 1];
    var minPath = findPath(paths, grid, 0, 0);
    return minPath;
};

var findPath = (paths, grid, i, j) => {
    if(i>=0 && i<grid.length && j >= 0 && j < grid[0].length){
        if(paths[i][j] >= 0){
            return paths[i][j];
        }
        let l = findPath(paths, grid, i+1, j);
        let r = findPath(paths, grid, i, j+1);
        if(l >= 0 && r >= 0){
            paths[i][j] = Math.min(l, r) + grid[i][j];    
        } else if(l >= 0){
            paths[i][j] = l + grid[i][j];    
        } else if(r >= 0){
            paths[i][j] = r + grid[i][j];    
        }
        
        return paths[i][j];
        
    }
    return -1;
}
