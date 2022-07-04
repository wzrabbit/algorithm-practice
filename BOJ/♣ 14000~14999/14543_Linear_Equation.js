const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let printer = '';

for (let i = 1; i < input.length; i++) {
    const [x, c, r] = input[i].split(/x \+ | = /).map((x) => parseInt(x));

    if (x === 0) {
        printer += `Equation ${i}\n`;

        if (c === r)
            printer += 'More than one solution.\n\n';
        else
            printer += 'No solution.\n\n';
    }
    else {
        let calc = ((r - c) / x).toFixed(10);
        let integer = calc.split('.')[0];
        let decimal = calc.split('.')[1] || '';

        if (decimal.length > 6)
            calc = integer + '.' + decimal.slice(0, 6);
        else if (decimal.length < 6)
            calc = integer + '.' + decimal + '0'.repeat(6 - decimal.length);

        printer += `Equation ${i}\nx = ${calc}\n\n`;
    }
}

console.log(printer);