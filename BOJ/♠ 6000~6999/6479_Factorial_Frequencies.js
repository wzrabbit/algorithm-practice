const input = require('fs').readFileSync('/dev/stdin').
    toString().trim().split('\n').map((x) => BigInt(x));
let printer = '';

function print(raw) {
    num = fact[raw].toString();
    let count = new Array(10).fill(0);

    for (let i = 0; i < num.length; i++)
        count[num[i]]++;

    printer += raw + '! --\n   ';
    for (let i = 0; i <= 4; i++) {
        printer += '(' + i + ')' + ' '.repeat(5 - count[i].toString().length) + count[i];
        if (i !== 4)
            printer += '    ';
    }
    printer += '\n   ';
    for (let i = 5; i <= 9; i++) {
        printer += '(' + i + ')' + ' '.repeat(5 - count[i].toString().length) + count[i];
        if (i !== 9)
            printer += '    ';
    }
    printer += '\n';
}

let fact = new Array(367).fill(0);
fact[1] = 1n;

for (let i = 2n; i <= 366n; i++)
    fact[i] = fact[i - 1n] * i;

for (let i = 0; i <= input.length - 3; i += 2)
    print(input[i]);

console.log(printer);