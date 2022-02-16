const [start, end] = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map((x) => parseInt(x));
let visited = Array(200001).fill(false);

bfs();

function bfs() {
  let queue = [[start, 0]];
  while (queue.length !== 0) {
    const [location, time] = queue.shift();
    if (location === end) {
      console.log(time);
      return;
    }
    if (location < 200000 && visited[location + 1] === false) {
      visited[location + 1] = true;
      queue.push([location + 1, time + 1]);
    }
    if (location <= 100000 && visited[location * 2] === false) {
      visited[location * 2] = true;
      queue.push([location * 2, time + 1]);
    }
    if (location > 0 && visited[location - 1] === false) {
      visited[location - 1] = true;
      queue.push([location - 1, time + 1]);
    }
  }
}