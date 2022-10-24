const getSum = (a, b) => {
    const mul = (a * b).toString().split('').map(x => parseInt(x));
    const sum = mul.reduce((x, y) => x + y);

    return sum;
}

let [N, raw] = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n');
N = parseInt(N);
raw = raw.split(' ').map(x => parseInt(x));
const count = new Array(1000).fill(0);
const arr = [];

for (let i = 0; i < N; i++) {
    count[raw[i]]++;
}

for (let i = 1; i <= 999; i++) {
    if (count[i] >= 2) {
        arr.push(i);
    }

    if (count[i] >= 1) {
        arr.push(i);
    }
}

let best = 0;
for (let i = 0; i < arr.length - 1; i++) {
    for (let j = i + 1; j < arr.length; j++) {
        let cur = getSum(arr[i], arr[j]);
        if (cur > best) {
            best = cur;
        }
    }
}

console.log(best);