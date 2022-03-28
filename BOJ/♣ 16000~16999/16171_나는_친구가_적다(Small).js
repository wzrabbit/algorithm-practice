const [before, after] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

if (before.replace(/\d/g, '').includes(after)) console.log(1);
else console.log(0);
