class Queue {
  constructor() {
    this.queue = [];
    this.front = 0;
  }

  push(value) {
    this.queue.push(value);
  }

  pop() {
    const popped = this.queue[this.front];
    this.front += 1;

    return popped;
  }

  isEmpty() {
    return this.queue.length - this.front === 0;
  }
}

const useWard = (startR, startC) => {
  const queue = new Queue();
  const letter = info[startR][startC];
  queue.push([startR, startC]);
  visited[startR][startC] = true;

  while (!queue.isEmpty()) {
    const [curR, curC] = queue.pop();

    for (let i = 0; i < 4; i++) {
      const r = curR + dr[i];
      const c = curC + dc[i];

      if (
        r < 0 ||
        r >= R ||
        c < 0 ||
        c >= C ||
        visited[r][c] ||
        info[r][c] !== letter
      ) {
        continue;
      }

      queue.push([r, c]);
      visited[r][c] = true;
    }
  }
};

const input = require("fs").readFileSync(0, "utf-8").trim().split("\n");

let index = 0;

const [R, C] = input[index++].split(" ").map(Number);
const info = [];
const visited = Array.from({ length: R }).map(() =>
  Array.from({ length: C }).fill(false),
);
const dr = [-1, 1, 0, 0];
const dc = [0, 0, -1, 1];

for (let r = 0; r < R; r++) {
  info.push(input[index++].split(""));
}

let [posR, posC] = input[index++].split(" ").map((value) => Number(value) - 1);

const commands = input[index++].split("");

commands.forEach((command) => {
  switch (command) {
    case "U":
      posR -= 1;
      break;
    case "D":
      posR += 1;
      break;
    case "L":
      posC -= 1;
      break;
    case "R":
      posC += 1;
      break;
    default:
      useWard(posR, posC);
      break;
  }
});

visited[posR][posC] = true;

for (let i = 0; i < 4; i++) {
  let r = posR + dr[i];
  let c = posC + dc[i];

  if (r >= 0 && r < R && c >= 0 && c < C) {
    visited[r][c] = true;
  }
}

let result = "";

for (let r = 0; r < R; r++) {
  for (let c = 0; c < C; c++) {
    result += visited[r][c] ? "." : "#";
  }

  result += "\n";
}

console.log(result);
