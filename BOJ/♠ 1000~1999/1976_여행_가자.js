const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const city = parseInt(input[0]);
const pathLength = parseInt(input[1]);
const graph = input.slice(2, city + 2).map((x) => x.split(' ').map((y) => parseInt(y)));

for (let m = 0; m < city; m++) {
  for (let s = 0; s < city; s++) {
    for (let e = 0; e < city; e++) {
      if (graph[s][m] + graph[m][e] === 2 || s === e) graph[s][e] = 1;
    }
  }
}

const path = input[city + 2].split(' ').map((x) => parseInt(x) - 1);
let isConnected = 'YES';
for (let i = 0; i < pathLength - 1; i++) {
    if (graph[path[i]][path[i + 1]] === 0) {
        isConnected = 'NO';
        break;
    }
}

console.log(isConnected);