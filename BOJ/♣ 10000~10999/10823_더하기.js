const numbers = require('fs').readFileSync(0, 'utf-8').replace(/\n| /g, '').split(',').map(Number);
const total = numbers.reduce((acc, cur) => acc + cur, 0);

console.log(total);
