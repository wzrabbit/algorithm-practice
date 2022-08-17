const input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n');
let printer = '';

for (let i = 0; i < input.length - 1; i++) {
    let str = input[i];
    if (str[str.length - 1] === 'o') {
        if ((str.match(/1/g) || []).length % 2 === 0)
            printer += str.slice(0, -1) + '1\n';
        else
            printer += str.slice(0, -1) + '0\n';
    }
    else {
        if ((str.match(/1/g) || []).length % 2 === 0)
            printer += str.slice(0, -1) + '0\n';
        else
            printer += str.slice(0, -1) + '1\n';
    }
}

console.log(printer);