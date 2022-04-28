const [min_, max_] = require('fs').readFileSync('/dev/stdin').
    toString().trim().split(' ').map((x) => parseInt(x));

let num = new Array(max_ - min_ + 1).fill(true);
let sieve = new Array(1000001).fill(true);
let finalSieve = [];

for (let i = 2; i <= 1000; i++) {
    if (!sieve[i])
        continue;

    for (let j = i * 2; j <= 1000000; j += i) {
        sieve[j] = false;
    }
}

for (let i = 2; i <= 1000000; i++) {
    if (sieve[i])
        finalSieve.push(i ** 2);
}

for (let i = 0; i < finalSieve.length; i++) {
    let start = finalSieve[i] - (min_ % finalSieve[i]);
    if (start === finalSieve[i])
        start = 0;

    for (let j = start; j < num.length; j += finalSieve[i])
        num[j] = false;
}

let result = 0;
for (let i = 0; i < num.length; i++)
    if (num[i])
        result++;

console.log(result);