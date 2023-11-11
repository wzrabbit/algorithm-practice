const convertTimeToNumber = (time) => {
  const [hh, mm] = time.split(':').map(Number);

  return (hh * 60 + mm) % 720;
};

const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const M = Number(input[0]);
const records = input.slice(1).map(
  (record) => convertTimeToNumber(record)
);

let N = M;

for (let r = 1; r <= 720; r++) {
  const clocks = new Set();
  minusTime = records[0];
  clocks.add(0);

  for (let i = 1; i < M; i++) {
    minusTime = (minusTime + r) % 720;

    const currentValue = (records[i] + 720 - minusTime) % 720;

    if (!clocks.has(currentValue)) {
      clocks.add(currentValue);
    }
  }

  N = Math.min(N, clocks.size);
}

console.log(N);
