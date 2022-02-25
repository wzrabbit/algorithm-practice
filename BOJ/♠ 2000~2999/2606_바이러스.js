const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
input.shift();
input.shift();

let graph = Array(101).fill([]);
for (let i = 0; i < input.length; i++) {
    let x = input[i].split(' ').map(Number);
    graph[x[0]] = [...graph[x[0]], x[1]];
    graph[x[1]] = [...graph[x[1]], x[0]];
}

let visited = Array(101).fill(false);
let result = -1;
dfs(1);

console.log(result);

function dfs(current) {
    visited[current] = true;
    result++;

    for (let i = 0; i < graph[current].length; i++) {
        if (visited[graph[current][i]] === false) dfs(graph[current][i]);
    }
}