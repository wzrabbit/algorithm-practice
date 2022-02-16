const graph = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((x) => x.split(''));

let comb = [];
function getComb(current, limit, list) {
  let data = graph[parseInt(current / 5)][current % 5];
  if (data === 'Y') limit++;
  list.push(current);
  if (limit >= 4 || 24 - current < 7 - list.length) return;
  if (list.length === 7) {
    comb.push(list);
    return;
  }
  for (let i = current + 1; i <= 24; i++) {
    getComb(i, limit, list.slice());
  }
}

let result = 0;
let dr = [-1, 1, 0, 0];
let dc = [0, 0, -1, 1];
function checkConnected(comb) {
  let visited = new Array(5).fill(true).map((x) => new Array(5).fill(true));
  let index = 0;
  let first = [parseInt(comb[0] / 5), comb[0] % 5];
  let queue = [first];

  for (let i = 0; i <= 6; i++) {
    let u = comb[i];
    visited[parseInt(u / 5)][u % 5] = false;
  }
  visited[first[0]][first[1]] = true;

  while (queue.length !== index) {
    let [r_, c_] = queue[index];
    index++;

    for (let i = 0; i <= 3; i++) {
      let [r, c] = [r_ + dr[i], c_ + dc[i]];
      if (r >= 0 && r <= 4 && c >= 0 && c <= 4 && visited[r][c] === false) {
        visited[r][c] = true;
        queue.push([r, c]);
      }
    }
  }

  if (queue.length === 7) {
    result++;
  }
}

for (let i = 0; i <= 18; i++) {
  getComb(i, 0, []);
}

for (let i = 0; i < comb.length; i++) {
  checkConnected(comb[i]);
}
console.log(result);