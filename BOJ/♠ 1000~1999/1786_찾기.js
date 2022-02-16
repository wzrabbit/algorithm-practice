const input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
const board = input[0];
const word = input[1];
let count = 0;
let result = '';

// KMP Table
let table = new Array(word.length).fill(0);
for (let l = 0, r = 1; r < word.length; r++) {
  while (l > 0 && word[l] !== word[r]) l = table[l - 1];
  if (word[l] === word[r]) {
    table[r] = l + 1;
    l++;
  }
}

// KMP Search
let index = 0;
for (let i = 0; i < board.length; i++) {
  while (index > 0 && board[i] !== word[index]) {
    index = table[index - 1];
  }
  if (board[i] === word[index]) {
    if (index === word.length - 1) {
      success = true;
      index = table[index];
      count++;
      result += i - word.length + 2 + ' ';
    }
    else index++;
  }
}

console.log(count);
console.log(result);