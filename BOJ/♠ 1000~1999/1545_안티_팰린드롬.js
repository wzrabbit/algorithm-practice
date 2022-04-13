const input = require('fs').readFileSync('/dev/stdin').toString().trim();
let alphabet = new Array(26).fill(0);
const limit = input.length - Math.floor(input.length / 2);

for (let i = 0; i < input.length; i++)
    alphabet[input[i].charCodeAt() - 97]++;

const maxIndex = alphabet.indexOf(Math.max(...alphabet));
let alphabetLeft = alphabet.slice();
if (alphabet[maxIndex] <= limit) {
    let result = [];
    let index = 0;
    let indexA = 0;

    while (index < limit) {
        if (alphabetLeft[indexA] > 0) {
            result.push(String.fromCharCode(indexA + 97));
            alphabetLeft[indexA] -= 1;
            index++;
        }

        if (alphabetLeft[indexA] === 0)
            indexA++;
    }

    const temp = String.fromCharCode(indexA + 97);
    let space =
        result.filter((x) => x === String.fromCharCode(indexA + 97)).length +
        ((input.length % 2 === 1) ? -1 : 0);
    const leftIndex = indexA;

    indexA++;
    while (index < limit + space) {
        if (alphabetLeft[indexA] > 0) {
            result.push(String.fromCharCode(indexA + 97));
            alphabetLeft[indexA] -= 1;
            index++;
        }

        if (alphabetLeft[indexA] === 0)
            indexA++;
    }

    while (alphabetLeft[leftIndex] > 0) {
        result.push(temp);
        alphabetLeft[leftIndex]--;
        index++;
    }

    while (index <= input.length - 1) {
        if (alphabetLeft[indexA] > 0) {
            result.push(String.fromCharCode(indexA + 97));
            alphabetLeft[indexA] -= 1;
            index++;
        }

        if (alphabetLeft[indexA] === 0)
            indexA++;
    }

    console.log(result.join(''));
}
else
    console.log(-1);
