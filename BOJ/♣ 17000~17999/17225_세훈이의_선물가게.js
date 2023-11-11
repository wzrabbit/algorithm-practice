const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const [A, B] = input[0].split(' ').map(Number);
const tasks = input.slice(1).map((task) => {
  const [time, color, count] = task.split(' ');

  return [Number(time), color, Number(count)];
});

const INF = 987_654_321;

const aTasks = [];
const bTasks = [];
const aIds = [];
const bIds = [];
let id = 1;

tasks.forEach(([time, color, count]) => {
  if (color === 'B') {
    aTasks.push([time, count]);
  } else {
    bTasks.push([time, count]);
  }
});

while (aTasks.length > 0 || bTasks.length > 0) {
  const aTime = aTasks[0] === undefined ? INF : aTasks[0][0];
  const bTime = bTasks[0] === undefined ? INF : bTasks[0][0];

  if (aTime <= bTime) {
    aTasks[0][0] += A;
    aTasks[0][1] -= 1;
    aIds.push(id++);

    if (aTasks[0][1] === 0) {
      const lastTime = aTasks[0][0];
      aTasks.shift();

      if (aTasks.length > 0) {
        aTasks[0][0] = Math.max(aTasks[0][0], lastTime);
      }
    }
  } else {
    bTasks[0][0] += B;
    bTasks[0][1] -= 1;
    bIds.push(id++);

    if (bTasks[0][1] === 0) {
      const lastTime = bTasks[0][0];
      bTasks.shift();

      if (bTasks.length > 0) {
        bTasks[0][0] = Math.max(bTasks[0][0], lastTime);
      }
    }
  }
}

console.log(aIds.length);
console.log(aIds.join(' '));
console.log(bIds.length);
console.log(bIds.join(' '));
