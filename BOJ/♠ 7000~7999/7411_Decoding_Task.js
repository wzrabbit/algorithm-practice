let [textA, textB] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
textA = textA.match(/.{2}/g).map((x) => parseInt(x, 16));
textB = textB.match(/.{2}/g).map((x) => parseInt(x, 16));
let answer = [];

answer.push(textB[0] ^ 32);
for (let i = 0; i < textA.length; i++)
    answer.push(textA[i] ^ textB[i + 1] ^ answer[answer.length - 1]);

answer = answer.map((x) => x.toString(16).toUpperCase());

for (let i = 0; i < answer.length; i++) {
    if (answer[i].length === 1)
        answer[i] = '0' + answer[i];
}

console.log(answer.join(''));
