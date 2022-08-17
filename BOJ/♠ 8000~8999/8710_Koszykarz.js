const [before, after, hit] = require('fs').readFileSync(0, 'utf-8')
    .toString().trim().split(' ').map((x) => parseInt(x));

console.log(Math.ceil((after - before) / hit));