const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const ppl = parseInt(input[0].split(' ')[0]);
const rel = parseInt(input[0].split(' ')[1]);
input.shift();

let graph = Array(ppl).fill([]);
for (let i = 0; i < rel; i++) {
    data = input[i].split(' ');
    graph[data[0]] = [...graph[data[0]], data[1]];
    graph[data[1]] = [...graph[data[1]], data[0]];
}

let abcde = 0;

for (let i = 0; i < ppl; i++) {
    if (abcde === 1) break;
    let visited = Array(ppl).fill(false);
    dfs(i, 0, visited);

    function dfs(current, combo) {
        if (abcde === 1) return;
        visited[current] = true;
        if (combo === 4) {
            abcde = 1;
            return;
        }
        for (let i = 0; i < graph[current].length; i++) {
            if (visited[graph[current][i]] === false) {
                dfs(graph[current][i], combo + 1);
            }
        }
        visited[current] = false;
    }
}

console.log(abcde);
