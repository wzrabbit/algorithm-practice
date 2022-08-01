const frag = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let printer = '';

frag.sort((a, b) => {
    return a + b > b + a ? -1 : 1;
});

for (let i = 0; i < frag.length; i++)
    printer += frag[i];

console.log(printer);