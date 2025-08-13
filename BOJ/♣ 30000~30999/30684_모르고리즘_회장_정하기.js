const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
console.log(input.slice(1).filter((name) => name.length === 3).sort()[0]);
