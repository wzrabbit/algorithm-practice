const word = require('fs').readFileSync('/dev/stdin').toString().trim();
let wordList = [];

for (let i = 0; i < word.length; i++)
    wordList.push(word.slice(i));

wordList.sort();

console.log(wordList.join('\n'));