let input = require('fs').readFileSync('/dev/stdin').toString().trim();

if (input.includes('A'))
    input = input.replace(/[BCDF]/g, 'A');
else if (input.includes('B'))
    input = input.replace(/[CDF]/g, 'B');
else if (input.includes('C'))
    input = input.replace(/[DF]/g, 'C');
else
    input = 'A'.repeat(input.length);

console.log(input);