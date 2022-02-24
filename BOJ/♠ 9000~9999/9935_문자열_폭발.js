const [word, bomb] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const bombLastWord = bomb[bomb.length - 1];
let stack = [];

for (let i = 0; i < word.length; i++) {
  stack.push(word[i]);
  if (word[i] === bombLastWord && stack.length >= bomb.length) {
    let checkWord = [];
    for (let j = 0; j < bomb.length; j++) {
      checkWord.unshift(stack.pop());
    }
    if (checkWord.join('') !== bomb) {
      for (let j = 0; j < bomb.length; j++) {
        stack.push(checkWord.shift());
      }
    }
  }
}
if (stack.length === 0) console.log('FRULA');
else console.log(stack.join(''));