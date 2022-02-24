const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [col, row] = input[0].split(' ').map(Number);
let queue = [];
let index = 0;
let max = 1;

for (let i = 1; i < input.length; i++) {
  input[i] = input[i].split(' ').map(Number);
}

let graph = input.slice(1);
let flag = true;
for (let r = 0; r < row; r++) {
  for (let c = 0; c < col; c++) {
    if (graph[r][c] === 1) queue.push([r, c, 1]);
  }
}

bfs();

if (isAllTomatoRiped()) {
  console.log(max - 1);
}
else {
  console.log(-1);
}

function bfs() {
  while (index < queue.length) {
    [r, c, d] = queue[index];
    index++;
    if (r > 0) {
       if (graph[r - 1][c] === 0) {
         graph[r - 1][c] = d + 1;
         if (d + 1 > max) max = d + 1;
         queue.push([r - 1, c, d + 1]);
       }
    }
    if (r < row - 1) {
      if (graph[r + 1][c] === 0) {
        graph[r + 1][c] = d + 1;
        if (d + 1 > max) max = d + 1;
        queue.push([r + 1, c, d + 1]);
      }
    }
    if (c > 0) {
      if (graph[r][c - 1] === 0) {
        graph[r][c - 1] = d + 1;
        if (d + 1 > max) max = d + 1;
        queue.push([r, c - 1, d + 1]);
      }
    }
    if (c < col - 1) {
      if (graph[r][c + 1] === 0) {
        graph[r][c + 1] = d + 1;
        if (d + 1 > max) max = d + 1;
        queue.push([r, c + 1, d + 1]);
      }
    }
  }
}

function isAllTomatoRiped() {
  for (let r = 0; r < row; r++) {
    for (let c = 0; c < col; c++) {
      if (graph[r][c] === 0) return false;
    }
  }
  return true;
}