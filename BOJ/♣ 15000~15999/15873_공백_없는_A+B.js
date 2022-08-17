const [A, B] = require('fs').readFileSync('/dev/stdin').toString().trim().match(/10|\d/g).map((x) => parseInt(x));
console.log(A + B);