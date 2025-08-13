const [word, ...input] = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
let searchCount = 0;

input.forEach((line) => {
    const searchRegex = new RegExp(word, 'g');
    searchCount += (line.match(searchRegex) || []).length;
});

console.log(searchCount);
