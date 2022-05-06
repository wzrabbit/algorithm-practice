const words = require('fs').readFileSync('/dev/stdin').toString().trim().split(/ |-/g);
let count = 0;

console.log(words);

for (let i = 0; i < words.length; i++) {
    count++;
    if (/^([cjnmtsld]|qu)'[aeiouh]/.test(words[i]))
        count++;
}

console.log(count);