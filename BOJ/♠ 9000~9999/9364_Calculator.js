const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let printer = '';

for (let i = 1; i < input.length; i += 2) {
    const core = parseInt(input[i]);
    let exp = input[i + 1].match(/(^|[-+])[0-9^X]+/g);
    let total = 0;

    for (let i = 0; i < exp.length; i++) {
        let num = exp[i];
        if (!num.includes('X'))
            total += parseInt(num);
        else if (!num.includes('^')) {
            num = num.replace('X', '');

            if (num === '' || num === '+')
                num = '1';
            else if (num === '-')
                num = '-1';

            total += parseInt(num) * core;
        }
        else {
            const [mul, pow] = num.split('X^').map((x) => parseInt(x));
            total += mul * (core ** pow);
        }
    }

    printer += `Case #${Math.ceil(i / 2)}: ${total}\n`;
}

console.log(printer);