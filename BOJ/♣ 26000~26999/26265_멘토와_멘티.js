const [_, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n')
  .map((line) => line.split(' '));

input.sort((a, b) => {
  if (a[0] !== b[0]) {
    return a[0] < b[0] ? -1 : 1;
  }

  return a[1] < b[1] ? 1 : -1;
});

console.log(
  input.map(([a, b]) => `${a} ${b}`).join('\n')
);
