function solve(exp, word) {
    let regex = new RegExp('^' + exp.replace('_', '.') + '$');
    if (!regex.test(word))
        return '!';

    let answer = null;
    const alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
    for (let i = 0; i < 26; i++) {
        regex = new RegExp('^' + exp.replace('_', alphabet[i]) + '$');
        if (regex.test(word)) {
            if (answer === null)
                answer = alphabet[i];
            else
                return '_';
        }
    }

    return answer;
}

const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let printer = '';

for (let i = 1; i < input.length; i += 2) {
    const exp = input[i];
    const word = input[i + 1];

    printer += solve(exp, word) + '\n';
}

console.log(printer);