let input = require('fs').readFileSync('/dev/stdin').toString().trim();
input = input.replace(/X{4}/g, 'AAAA');
input = input.replace(/X{2}/g, 'BB');
if (input.includes('X')) console.log(-1);
else console.log(input);