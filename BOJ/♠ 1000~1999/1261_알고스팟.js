const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [col, row] = input[0].split(' ').map((x) => parseInt(x));
let visited = new Array(row).fill(0).map((x) => new Array(col).fill(false));
let maze = new Array(row);
for (let i = 0; i < row; i++) {
  maze[i] = input[i + 1].split('');
}

function bfs() {
  let queue = [[0, 0, 0]];
  const dr = [1, 0, -1, 0];
  const dc = [0, 1, 0, -1];
  while (queue.length > 0) {
    const [r_, c_, d] = queue.shift();
    if (visited[r_][c_] === true) continue;
    visited[r_][c_] = true;
    if (r_ === row - 1 && c_ === col - 1) {
      console.log(d);
      return;
    }
    for (let i = 0; i <= 3; i++) {
      const [r, c] = [r_ + dr[i], c_ + dc[i]];
      if (r >= 0 && r < row && c >= 0 && c < col && visited[r][c] === false) {
        if (maze[r][c] === '1') queue.push([r, c, d + 1]);
        else queue.unshift([r, c, d]);
      }
    }
  }
}

bfs();