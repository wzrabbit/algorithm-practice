const abs = (x) => {
  if (x > 0n) {
    return x;
  }

  return -x;
}

const getPriorityScore = ([x, y]) => {
  if (x === 0n && y > 0n) {
    return 1;
  }

  if (x < 0n && y > 0n) {
    return 2;
  }

  if (x < 0n && y === 0n) {
    return 3;
  }

  if (x < 0n && y < 0n) {
    return 4;
  }

  if (x === 0n && y < 0n) {
    return 5;
  }

  if (x > 0n && y < 0n) {
    return 6;
  }

  if (x > 0n && y === 0n) {
    return 7;
  }

  return 8;
};

const sortPositions = (a, b) => {
  a = [a[0] - hyukPosition[0], a[1] - hyukPosition[1]];
  b = [b[0] - hyukPosition[0], b[1] - hyukPosition[1]];

  const aPriority = getPriorityScore(a);
  const bPriority = getPriorityScore(b);

  if (aPriority !== bPriority) {
    return aPriority - bPriority;
  }

  const [ax, ay] = a;
  const [bx, by] = b;

  if (aPriority % 2 === 0 && ax * by !== bx * ay) {
    return ax * by > bx * ay ? -1 : 1;
  }

  if (abs(ax) !== abs(bx)) {
    return abs(ax) > abs(bx) ? 1 : -1;
  }

  return abs(ay) > abs(by) ? 1 : -1;
};

const input = require("fs").readFileSync(0, "utf-8").trim().split("\n");

const N = Number(input[0]);
const positions = input
  .slice(1, N + 1)
  .map((position) => position.split(" ").map(BigInt));
const hyukPosition = input.at(-1).split(" ").map(BigInt);

positions.sort(sortPositions);

let output = '';

positions.forEach(([x, y]) => {
  output += `${x} ${y}\n`;
});

console.log(output);
