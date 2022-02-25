const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const width = parseInt(input[0]);
input.shift();

let graph = input.slice();
for (let i = 0; i < width; i++) {
    graph[i] = graph[i].split('');
}

let graphBlind = input.slice();
for (let i = 0; i < width; i++) {
    graphBlind[i] = graphBlind[i].split('');
}
for (let i = 0; i < width; i++) {
    for (let j = 0; j < width; j++) {
        if (graphBlind[i][j] === 'G') graphBlind[i][j] = 'R';
    }
}

graphCount = 0;
graphBlindCount = 0;

for (let i = 0; i < width; i++) {
    for (let j = 0; j < width; j++) {
        if (graph[i][j] !== 'X') {
            graphCount++;
            dfs(0, graph[i][j], [i, j]);
        }
        if (graphBlind[i][j] !== 'X') {
            graphBlindCount++;
            dfs(1, graphBlind[i][j], [i, j]);
        }
    }
}

console.log(graphCount, graphBlindCount);

function dfs(mode, color, [row, col]) {
    let thisGraph = (mode === 1) ? graphBlind : graph;
    thisGraph[row][col] = 'X';

    if (row > 0) {
        if (thisGraph[row - 1][col] === color) dfs(mode, color, [row - 1, col]);
    }
    if (col > 0) {
        if (thisGraph[row][col - 1] === color) dfs(mode, color, [row, col - 1]);
    }
    if (row < width - 1) {
        if (thisGraph[row + 1][col] === color) dfs(mode, color, [row + 1, col]);
    }
    if (col < width - 1) {
        if (thisGraph[row][col + 1] === color) dfs(mode, color, [row, col + 1]);
    }
}
