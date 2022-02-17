let word = require('fs').readFileSync('/dev/stdin').toString().trim();
word = word.replace(/([aeiou])p\1/g, (w) => { return w[0] });
console.log(word);