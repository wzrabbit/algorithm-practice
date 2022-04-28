const input = require('fs').readFileSync('/dev/stdin').toString().trim();
console.log(input.match(/[A-Z]/g).join(''));