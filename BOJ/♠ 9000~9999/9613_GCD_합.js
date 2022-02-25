const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let result = '';

for (let i = 1; i < input.length; i++) {
    let current = input[i].split(' ').map(Number);
    let sum = 0;
    for (let j = 1; j < current.length; j++) {
        for (let k = j + 1; k < current.length; k++) {
            sum += getGcd(current[j], current[k]);
        }
    }
    result += sum + '\n';
}

console.log(result);

function getGcd(a, b) {
    if (a < b) [a, b] = [b, a];
    while (true) {
        let c = a % b;
        if (c) {
            a = b;
            b = c;
        }
        else return b;
    }
}