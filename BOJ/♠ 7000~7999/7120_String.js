let input = require('fs').readFileSync('/dev/stdin').toString().trim();
input = input.replace(/(.)\1*/g, (word) => { return word[0]; });
console.log(input);