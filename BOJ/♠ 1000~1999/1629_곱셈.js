const [a, b, c] = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map(BigInt);

// 분할 정복을 이용한 거듭제곱 - 시간복잡도 O(log2n)
// n이 홀수 -> n * n^((m-1)/2) * n^((m-1)/2)
// n이 짝수 -> n^(m/2) * n^(m/2)

function enhancedPow(n, m) {
    if (m === 0n) return 1n;

    let p = m % 2n ? (m - 1n) / 2n : m / 2n;
    let d = enhancedPow(n, p);
    let t = d * d % c;
    if (m % 2n === 0n) return t;
    else return (n * t) % c;
}

console.log(enhancedPow(a, b).toString());