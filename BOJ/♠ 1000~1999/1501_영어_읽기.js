const getSortedWord = word => {
    if (word.length <= 2)
        return word;

    return word[0] +
        word.slice(1, word.length - 1).split('').sort().join('') +
        word[word.length - 1];
}

const input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n');
let l = 0;
let wordMap = new Map();
let printer = '';

const W = parseInt(input[l]);
while (++l <= W) {
    const sortedWord = getSortedWord(input[l]);

    if (wordMap.has(sortedWord))
        wordMap.set(sortedWord, wordMap.get(sortedWord) + 1);
    else
        wordMap.set(sortedWord, 1);
}

const S = W + 1 + parseInt(input[l]);
while (++l <= S) {
    let answer = 1;
    const sentence = input[l].trim().split(' ');

    for (let i = 0; i < sentence.length; i++) {
        if (!wordMap.get(getSortedWord(sentence[i].trim()))) {
            answer = 0;
            break;
        }
        else
            answer *= wordMap.get(getSortedWord(sentence[i]));
    }

    printer += answer + '\n';
}

console.log(printer);