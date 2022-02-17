const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const width = parseInt(input[0]);
let maxHeight = 1;
let maxLand = 0;
let graph;
input.shift();

for (let i = 0; i < width; i++) {
  input[i] = input[i].split(' ').map((x) => parseInt(x));
}

for (let r = 0; r < width; r++) {
  for (let c = 0; c < width; c++) {
    if (input[r][c] > maxHeight) maxHeight = input[r][c];
  }
}

for (let rain = 0; rain <= maxHeight; rain++) {
  graph = input.map((x) => x.slice());
  let count = 0;
  for (let r = 0; r < width; r++) {
    for (let c = 0; c < width; c++) {
      if (graph[r][c] <= rain) graph[r][c] = 'X';
      else graph[r][c] = 'O';
    }
  }
  for (let r = 0; r < width; r++) {
    for (let c = 0; c < width; c++) {
      if (graph[r][c] === 'O') {
        count++;
        bfs(r, c);
      }
    }
  }

  if (maxLand < count) maxLand = count;
}

console.log(maxLand);

function bfs(startRow, startCol) {
  let queue = [[startRow, startCol]];

  while (queue.length !== 0) {
    const [r, c] = queue.shift();

    if (r > 0 && graph[r - 1][c] === 'O') {
      graph[r - 1][c] = 'V';
      queue.push([r - 1, c]);
    }
    if (r < width - 1 && graph[r + 1][c] === 'O') {
      graph[r + 1][c] = 'V';
      queue.push([r + 1, c]);
    }
    if (c > 0 && graph[r][c - 1] === 'O') {
      graph[r][c - 1] = 'V';
      queue.push([r, c - 1]);
    }
    if (c < width && graph[r][c + 1] === 'O') {
      graph[r][c + 1] = 'V';
      queue.push([r, c + 1]);
    }
  }
}