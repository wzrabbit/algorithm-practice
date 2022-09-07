const [A, B, C] = require('fs').readFileSync(0, 'utf-8')
    .toString().trim().split(' ').map(x => parseInt(x));

if (C % 2 === 0)
    console.log(A);
else
    console.log(A ^ B)