const input = BigInt(require('fs').readFileSync('/dev/stdin'));

let start = 0n;
let end = BigInt(input);
let mid;

while (start < end) {
    mid = (start + end) / 2n;

    if (mid * mid >= input)
        start = mid + 1n;
    else
        end = mid - 1n;
}

console.log(end);