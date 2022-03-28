const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [n, m] = input[0].split(' ').map((x) => parseInt(x));
let num = input[1].split(' ').map((x) => parseInt(x)).sort((x, y) => x - y);
let result = [];
let visited = new Array(n).fill(false);
let attempt = [];
for (let i = 0; i < n; i++) {
    dfs(i, 1);
}

function dfs(current, len) {
    attempt.push(num[current]);
    visited[current] = true;
    if (len === m) {
        let produce = attempt.join(' ');
        if (!result.includes(produce)) {
            result.push(produce);
        }
        visited[current] = false;
        attempt.pop();
        return;
    }
    for (let i = 0; i < num.length; i++) {
        if (i != current && visited[i] == false) {
            dfs(i, len + 1);
        }
    }
    attempt.pop();
    visited[current] = false;
}

console.log(result.join('\n'));