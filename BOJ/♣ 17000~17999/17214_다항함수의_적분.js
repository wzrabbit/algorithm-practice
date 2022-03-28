let input = require('fs').readFileSync('/dev/stdin').toString().trim();
let result = '';

input = input.replace(/[-+]?\d+x/, (x) => {
    let num = parseInt(x.slice(0, -1)) / 2;
    if (num === -1) num = '-';
    else if (num === 1) num = '';
    result += num + 'xx';
    return '';
});

input = input.replace(/[-+]?\d+/, (x) => {
    if (x.startsWith('-')) {
        let num = parseInt(x);
        if (num === -1) num = '-';
        result += num + 'x';
    }
    else {
        let num = parseInt(x);
        if (num === 1) num = '';
        else if (num === 0) return '';
        if (result.length === 0) result += num + 'x';
        else result += '+' + num + 'x';
    }
    return '';
});

if (result.length === 0) result += 'W';
else result += '+W';

console.log(result);