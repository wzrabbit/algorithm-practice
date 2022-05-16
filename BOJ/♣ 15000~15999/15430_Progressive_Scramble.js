const input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
input.pop();
let n = input.shift();

let text, query;
let printer = '';

function encrypt() {
    text = text.map((x) => {
        if (x === ' ')
            return 0;
        else
            return x.charCodeAt() - 96;
    });

    for (let i = 1; i < text.length; i++)
        text[i] += text[i - 1];

    text = text.map((x) => x % 27);

    text = text.map((x) => {
        if (x === 0)
            return ' ';
        else
            return String.fromCharCode(x + 96);
    }).join('');
}

function decrypt() {
    let mul = 0;
    text = text.map((x) => {
        if (x === ' ')
            return 0;
        else
            return x.charCodeAt() - 96;
    });

    let archive = text.slice();
    for (let i = 1; i < text.length; i++) {
        if (archive[i] < archive[i - 1])
            mul++;
        text[i] = archive[i] + 27 * mul;
    }

    for (let i = text.length - 1; i >= 1; i--)
        text[i] -= text[i - 1];

    text = text.map((x) => {
        if (x === 0)
            return ' ';
        else
            return String.fromCharCode(x + 96);
    }).join('');
}

for (let i = 0; i < n; i++) {
    query = input[i][0];
    text = input[i].slice(2).split('');

    if (query === 'e')
        encrypt();
    else
        decrypt();

    printer += text + '\n';
}

console.log(printer);