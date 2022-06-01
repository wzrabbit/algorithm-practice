const [time, mul, fill, rStart, rEnd, cStart, cEnd]
    = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map((x) => parseInt(x));
printer = '';

function getValue(r, c, n) {
    let out = (mul - fill) / 2;
    if (r >= out * n && r < (fill + out) * n &&
        c >= out * n && c < (fill + out) * n)
        return '1';
    else if (n === 1)
        return '0';

    r = r % n;
    c = c % n;
    n /= mul;
    return getValue(r, c, n);
}

if (time === 0)
    console.log('0');
else {
    for (let r = rStart; r <= rEnd; r++) {
        for (let c = cStart; c <= cEnd; c++)
            printer += getValue(r, c, mul ** (time - 1));
        printer += '\n';
    }
}

console.log(printer);
