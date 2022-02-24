const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
[col, row, level] = input[0].split(' ').map(Number);
let queue = [];
let graph = [];
let index = 0;
let max = 1;

for (let i = 1; i < input.length; i += row) {
  graph.push(input.slice(i, i + row));
}
for (let i = 0; i < graph.length; i++) {
  for (let j = 0; j < graph[i].length; j++) {
    graph[i][j] = graph[i][j].split(' ').map(Number);
  }
}

let flag = true;
for (let l = 0; l < level; l++) {
  for (let r = 0; r < row; r++) {
    for (let c = 0; c < col; c++) {
      if (graph[l][r][c] === 1) queue.push([l, r, c, 1]);
    }
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
    [l, r, c, d] = queue[index];
    index++;
    if (r > 0 && graph[l][r - 1][c] === 0) {
       graph[l][r - 1][c] = d + 1;
       if (d + 1 > max) max = d + 1;
       queue.push([l, r - 1, c, d + 1]);
    }
    if (r < row - 1 && graph[l][r + 1][c] === 0) {
      graph[l][r + 1][c] = d + 1;
      if (d + 1 > max) max = d + 1;
      queue.push([l, r + 1, c, d + 1]);
    }
    if (c > 0 && graph[l][r][c - 1] === 0) {
      graph[l][r][c - 1] = d + 1;
      if (d + 1 > max) max = d + 1;
      queue.push([l, r, c - 1, d + 1]);
    }
    if (c < col - 1 && graph[l][r][c + 1] === 0) {
      graph[l][r][c + 1] = d + 1;
      if (d + 1 > max) max = d + 1;
      queue.push([l, r, c + 1, d + 1]);
    }
    if (l > 0 && graph[l - 1][r][c] === 0) {
       graph[l - 1][r][c] = d + 1;
       if (d + 1 > max) max = d + 1;
       queue.push([l - 1, r, c, d + 1]);
    }
    if (l < level - 1 && graph[l + 1][r][c] === 0) {
       graph[l + 1][r][c] = d + 1;
       if (d + 1 > max) max = d + 1;
       queue.push([l + 1, r, c, d + 1]);
    }
  }
}

function isAllTomatoRiped() {
  for (let l = 0;  l < level; l++) {
    for (let r = 0; r < row; r++) {
      for (let c = 0; c < col; c++) {
        if (graph[l][r][c] === 0) return false;
      }
    }
  }
  return true;
}