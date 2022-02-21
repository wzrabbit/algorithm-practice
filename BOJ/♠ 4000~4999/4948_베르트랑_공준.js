const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
input.pop();
let isPrime = new Array(246913).fill(true);
let answer = new Array(246913).fill(0);

for (let i = 2; i <= Math.sqrt(246912); i++) {
  if (isPrime[i]) {
    for (let j = i * 2; j <= 246912; j += i) {
      isPrime[j] = false;
    }
  }
}

for (let i = 2; i <= 246912; i++) {
  if (isPrime[i]) {
    answer[i] = answer[i - 1] + 1;
  }
  else answer[i] = answer[i - 1];
}

let result = '';
for (let i = 0; i < input.length; i++) {
  result += answer[input[i] * 2] - answer[input[i]] + '\n';
}

console.log(result);