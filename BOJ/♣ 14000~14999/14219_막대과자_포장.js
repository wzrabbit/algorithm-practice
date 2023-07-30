const [N, M] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split(' ')
  .map(Number);

console.log(N * M % 3 === 0 ? 'YES' : 'NO');