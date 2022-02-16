const input = require('fs').readFileSync('/dev/stdin').toString().trim();
const zero = (input.match(/1+/g) || []).length;
const one = (input.match(/0+/g) || []).length;
console.log(Math.min(zero, one));