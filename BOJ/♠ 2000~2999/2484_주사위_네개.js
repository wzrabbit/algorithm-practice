const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let max_ = 0;

for (let i = 1; i < input.length; i++) {
    const [a, b, c, d] = input[i].split(' ').map((x) => parseInt(x));
    const sorted = [a, b, c, d].sort();
    const count = new Set([a, b, c, d]).size;
    let current;

    if (sorted[0] === sorted[3])
        current = 50000 + a * 5000;
    else if (sorted[0] === sorted[2] || sorted[1] === sorted[3])
        current = 10000 + sorted[1] * 1000;
    else if (sorted[0] === sorted[1] && sorted[2] === sorted[3])
        current = 2000 + (sorted[0] + sorted[2]) * 500;
    else if (count === 3) {
        for (let i = 0; i < 3; i++) {
            if (sorted[i] === sorted[i + 1])
                current = 1000 + sorted[i] * 100;
        }
    }
    else
        current = Math.max(a, b, c, d) * 100;

    if (current > max_)
        max_ = current;
}

console.log(max_);