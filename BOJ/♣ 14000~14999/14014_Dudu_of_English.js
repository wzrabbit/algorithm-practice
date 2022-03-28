let input = require('fs').readFileSync('/dev/stdin').toString().replace(/^[0-9]+\n|\n$/g, '');
input = input.toLowerCase();
input = input.replace(/(?<=(^| ))(to|into|onto|above|below|from|by|is|at)(?=($| ))/gm, 'of');
input = input.replace(/[^\n ]+/g, (w) => {
    let eraseLength = Math.floor((w.match(/[aeiou]/g) || []).length / 2);
    let changedWord = '';
    for (let i = 0; i < w.length; i++) {
        if (eraseLength === 0 || !'aeiou'.includes(w[i])) changedWord += w[i];
        else eraseLength--;
    }
    return changedWord;
});
input = input.replace(/[^a-z\n ]/g, '');
input = input.replace(/\n/g, ' ');
input = input.replace(/ {2,}/g, ' ');

let printer = '';
let wordSplited = input.split(' ');
let len = 0;
for (let i = 0; i < wordSplited.length; i++) {
    if (wordSplited[i] === '') continue;
    len += wordSplited[i].length;
    printer += wordSplited[i];
    if (len > 20) {
        printer += '\n';
        len = 0;
    }
    else printer += ' ';
}

console.log(printer);