function getLowestSquare(num) {
    let start = 0n;
    let end = 10n ** 18n;
    let mid;

    while (start <= end) {
        mid = (start + end) / 2n;
        if (mid * mid >= num)
            end = mid - 1n;
        else
            start = mid + 1n;
    }

    return start;
}

function solve(num) {
    if (visited.has(num))
        return;

    visited.add(num);
    const x = getLowestSquare(num);
    const y = x * x - num;

    solve(x);
    solve(y);

    printer += `${x} ${y}\n`;
}

const goal = BigInt(require('fs').readFileSync('/dev/stdin'));
let printer = '';
let visited = new Set([0n, 1n, 2n]);
solve(goal);
console.log(printer);