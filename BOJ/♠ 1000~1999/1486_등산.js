const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [row, col, gap, dusk] = input[0].split(' ').map((x) => parseInt(x));
const inf = 10 ** 8;
const biome = input.slice(1, row + 1).map((x) => x.split('').map((y) => {
  if (y.charCodeAt() >= 97) return y.charCodeAt() - 71;
  else return y.charCodeAt() - 65;
}));

let graph = new Array(row * col).fill(0).map((x) => new Array(row * col).fill(inf));
let dr = [-1, 1, 0, 0];
let dc = [0, 0, -1, 1];
for (let i = 0; i < row * col; i++) {
  graph[i][i] = 0;
}
for (let r = 0; r < row; r++) {
  for (let c = 0; c < col; c++) {
    for (let i = 0; i <= 3; i++) {
      let r_ = r + dr[i];
      let c_ = c + dc[i];
      if (r_ >= 0 && r_ < row && c_ >= 0 && c_ < col) {
        let s = biome[r][c];
        let e = biome[r_][c_];
        if (Math.abs(s - e) <= gap) {
          if (s >= e) {
            graph[r * col + c][r_ * col + c_] = 1;
          }
          else {
            graph[r * col + c][r_ * col + c_] = (s - e) ** 2;
          }
        }
      }
    }
  }
}

for (let m = 0; m < row * col; m++) {
  for (let s = 0; s < row * col; s++) {
    for (let e = 0; e < row * col; e++) {
      if (s !== e && graph[s][e] > graph[s][m] + graph[m][e]) {
        graph[s][e] = graph[s][m] + graph[m][e];
      }
    }
  }
}

let max = biome[0][0];
for (let i = 1; i < row * col; i++) {
  if (biome[parseInt(i / col)][i % col] > max && graph[0][i] + graph[i][0] <= dusk) {
    max = biome[parseInt(i / col)][i % col];
  }
}

console.log(max);