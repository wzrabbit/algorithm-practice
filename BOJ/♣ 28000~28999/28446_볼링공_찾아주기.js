const [_, ...input] = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const storage = {};
let output = '';

input.forEach((query) => {
  const [queryNo, x, y] = query.split(' ').map(Number);

  if (queryNo === 1) {
    storage[y] = x;
  } else {
    output += `${storage[x]}\n`;
  }
});

console.log(output);

