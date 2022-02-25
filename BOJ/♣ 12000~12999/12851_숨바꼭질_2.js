const [start, end] = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map((x) => parseInt(x));
let visited = Array(100001).fill(false);
let count = 0;

bfs();

function bfs() {
  let queue = [[start, 0]];
  let index = 0;
  let fastestTime = 'none';
  let found = false;
  visited[start] = true;
  while (queue.length !== index) {
    const [location, time] = queue[index];
    visited[location] = true; // 같은 칸을 지나쳤더라도 오는 방법이 여러 가지일 수 있으므로 pop할 때 방문 표시
    index++;
    if (location === end && (fastestTime === time || fastestTime === 'none')) {
      if (found === false) {
        console.log(time);
        found = true;
        fastestTime = time;
      }
      count++;
    }
    if (found === false) {
      if (location < 100000 && visited[location + 1] === false) {
        queue.push([location + 1, time + 1]);
      }
      if (location <= 50000 && visited[location * 2] === false) {
        queue.push([location * 2, time + 1]);
      }
      if (location > 0 && visited[location - 1] === false) {
        queue.push([location - 1, time + 1]);
      }
    }
  }
}

console.log(count);