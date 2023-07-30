const [, input] = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
console.log((input.match(/[aeiou]/g) || []).length);