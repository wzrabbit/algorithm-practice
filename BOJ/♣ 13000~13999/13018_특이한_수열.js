const [num, match] = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map((x) => parseInt(x));
let printer = '';

if (num === match)
    console.log('Impossible');
else {
    for (let i = 2; i <= num - match; i++)
        printer += i + ' ';
    printer += '1 ';

    for (let i = num - match + 1; i <= num; i++)
        printer += i + ' ';

    console.log(printer);
}