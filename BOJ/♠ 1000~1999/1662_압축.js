// 쓰라는 재귀랑 스택은 안 쓰고 이상한 정규 표현식이나 갈긴 코드
let input = require('fs').readFileSync('/dev/stdin').toString().trim();

input = input.replace(/\d(?=\()/g, (word) => {
  let alphabet = 'ABCDEFGHIJ';
  return alphabet[parseInt(word)];
});

input = input.replace(/\d+/g, (word) => {
  return word.length;
});

while (input.includes('(')) {
  input = input.replace(/[A-J]\(\d*\)/, (word) => {
    let mul = word[0].charCodeAt() - 65;
    let digit = parseInt(word.split('(')[1].split(')')[0]) || 0;
    return '+' + mul * digit + '+';
  });

  input = input.replace(/\d*\+\d+\+\d*|\d*\+\d+/, (word) => {
    let wordList = word.split('+').map(Number);
    let sum = 0;
    wordList.forEach((w, i) => {
      if(isNaN(w)) wordList[i] = 0;
      sum += wordList[i];
    });
    return sum;
  });
}

console.log(input);