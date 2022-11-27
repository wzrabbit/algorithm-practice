const MAX_SIZE = 1_000_000;

const input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n').map(Number);
let numberCount = new Array(MAX_SIZE + 1).fill(0);
let hitCount = new Array(MAX_SIZE + 1).fill(0);
let printer = '';

for (let i = 1; i < input.length; i += 1) {
    numberCount[input[i]] += 1;
}

for (let i = 1; i <= MAX_SIZE; i += 1) {
    if (numberCount[i] === 0) continue;
    
    hitCount[i] += numberCount[i] - 1;

    for (let j = i * 2; j <= MAX_SIZE; j += i) {
        hitCount[j] += numberCount[i];
    }
}

for (let i = 1; i < input.length; i += 1) {
    printer += hitCount[input[i]] + '\n';
}

console.log(printer);
