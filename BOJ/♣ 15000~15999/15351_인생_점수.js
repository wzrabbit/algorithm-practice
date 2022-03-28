const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const num = parseInt(input.shift());
let result = '';

for (let i = 0; i < num; i++) {
    let word = (input[i] === undefined) ? '' : input[i];
    word = word.replace(/ /g, '');
    let score = 0;
    for (let j = 0; j < word.length; j++) {
        score += word[j].charCodeAt() - 64;
    }
    if (score === 100) result += 'PERFECT LIFE\n';
    else result += score + '\n';
}

console.log(result);