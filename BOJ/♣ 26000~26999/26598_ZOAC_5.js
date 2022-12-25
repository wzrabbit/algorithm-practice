const input = require('fs').readFileSync(0, 'utf-8').trim();
const matched = input.match(/(.)\1*/g);
console.log(matched[0].length);