/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    let visited = grid.map(r => r.map(v => false));
    let island = 0;
    //console.log(visited);
    let traverse = function(i, j, visited) {
        if(i >= 0 && i < grid.length && j >= 0 && j < grid[0].length && !visited[i][j] && grid[i][j] == '1'){
            visited[i][j] = true;
            traverse(i-1, j, visited);
            traverse(i, j-1, visited);
            traverse(i+1, j, visited);
            traverse(i, j+1, visited);
        }
    }
    for(let i=0; i<grid.length; i++){
        for(let j=0; j<grid[0].length; j++){
            if(grid[i][j] == '1' && !visited[i][j]){
                island++;
                traverse(i, j, visited);
            }
        }
    }
    return island;
};