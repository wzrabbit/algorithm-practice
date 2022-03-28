let input = require('fs').readFileSync('/dev/stdin').toString().trim();
let result = (input.match(/-?\d*(?=x)/) || ['NONE'])[0];
if (result === '-') result = -1;
else if (result === '') result = 1;
else if (result === 'NONE') result = 0;
console.log(result);