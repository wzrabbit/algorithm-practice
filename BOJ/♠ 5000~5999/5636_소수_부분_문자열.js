const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let prime = new Array(100001).fill(true);
let printer = '';

prime[0] = false;
prime[1] = false;

for (let i = 2; i <= 320; i++) {
    if (!prime[i])
        continue;

    for (let j = i * 2; j <= 100000; j += i)
        prime[j] = false;
}

for (let i = 0; i < input.length - 1; i++) {
    let maxPrime = 2; // 모든 입력에 소수가 최소 하나는 있다고 가정

    for (let j = 1; j <= 6; j++) {
        for (let k = 0; k < input[i].length - j + 1; k++) {
            const cur = parseInt(input[i].substr(k, j));
            if (cur <= 100000 && prime[cur] && cur > maxPrime)
                maxPrime = cur;
        }
    }

    printer += maxPrime + '\n';
}

console.log(printer);