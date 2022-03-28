const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

input.forEach((sentence, index) => {
    input[index] = sentence.replace(/(?=(\b|\.|,))[A-Z][a-z]+( [A-Z][a-z]+)+(?<=(\b|\.|,))/g, (word) => {
        return word.match(/[A-Z]/g).join('') + ' (' + word + ')';
    });
});

console.log(input.join('\n'));