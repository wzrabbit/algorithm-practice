class Queue {
  queue = [];
  front = 0;

  push(value) {
    this.queue.push(value);
  }

  pop() {
    const popped = this.queue[this.front];
    this.front += 1;
    return popped;
  }

  isEmpty() {
    return this.queue.length === this.front;
  }
}

const NONE = -1;
const MOD = 10_000;
const OPERATION_NAMES = ['D', 'S', 'L', 'R'];

const bfs = (start, end, visited, history) => {
  const queue = new Queue();
  queue.push(start);
  visited[start] = true;
  history[start] = [NONE, ''];

  while (!queue.isEmpty()) {
    const cur = queue.pop();
    const stringifiedCur = cur.toString().padStart(4, '0');

    if (cur === end) {
      return;
    }

    const nextValues = [
      cur * 2 % MOD,
      cur === 0 ? 9999 : cur - 1,
      Number(stringifiedCur.slice(1) + stringifiedCur[0]),
      Number(stringifiedCur[3] + stringifiedCur.slice(0, 3)),
    ];

    for (let i = 0; i < 4; i++) {
      const nextValue = nextValues[i];

      if (!visited[nextValue]) {
        visited[nextValue] = true;
        history[nextValue] = [cur, OPERATION_NAMES[i]];
        queue.push(nextValue);
      }
    }
  }
};

const writeHistory = (cur, history) => {
  const [prev, name] = history[cur];

  if (prev !== NONE) {
    writeHistory(prev, history);
  }

  output += name;
};

const [_, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

let output = '';

input.forEach((line) => {
  const [start, end] = line.split(' ').map(Number);

  const visited = new Array(10000).fill(false);
  const history = new Array(10000);

  bfs(start, end, visited, history);
  writeHistory(end, history);

  output += '\n';
});

console.log(output);
