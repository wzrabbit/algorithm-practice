const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let time = parseInt(input[0].split(' ')[0]) * 24;
let scores = new Array(100).fill(0);
const beforeScore = input[1].split(' ').map(Number);
const plus = input[2].split(' ').map(Number);
let beforeScoreSum = 0;
let finalSum = 0;

for (let i = 0; i < beforeScore.length; i++) {
    beforeScoreSum += beforeScore[i];
    scores[plus[i]] += parseInt((100 - beforeScore[i]) / plus[i]);
    scores[(100 - beforeScore[i]) % plus[i]] += 1;
}

for (let i = 99; i >= 1; i--) {
    if (scores[i] === 0) continue;
    if (time > scores[i]) {
        time -= scores[i];
        finalSum += i * scores[i];
    }
    else {
        finalSum += i * time;
        break;
    }
}

finalSum += beforeScoreSum;
console.log(finalSum);