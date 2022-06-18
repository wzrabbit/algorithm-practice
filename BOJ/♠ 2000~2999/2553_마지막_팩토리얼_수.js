const input = BigInt(require('fs').readFileSync('/dev/stdin'));
let num = 1n;

for (let i = 1n; i <= input; i++) {
    num *= i;
    while (num % 10n === 0n)
        num /= 10n;
    num = num % 1000000000n;
}

console.log((num % 10n).toString());