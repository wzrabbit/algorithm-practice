const input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n');
const N = parseInt(input[0]);
const arr = input[1].split(' ').map(x => parseInt(x));
let set = new Set();
const sum = arr.reduce((x, y) => x + y);

for (let i = 0; i < N; i++) {
    set.add(sum - arr[i]);
}

set = [...set].sort((a, b) => a - b);
console.log(set.length);
console.log(set.join(' '));