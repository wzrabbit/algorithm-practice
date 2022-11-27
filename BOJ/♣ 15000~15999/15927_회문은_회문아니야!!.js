const input = require('fs').readFileSync(0, 'utf-8').toString().trim();
let isSame = true;
let isPalindrome = true;
let firstCharacter = input[0];
let leftPointer = 0;
let rightPointer = input.length - 1;

while (leftPointer <= rightPointer) {
    if (input[leftPointer] !== firstCharacter || input[rightPointer] !== firstCharacter) {
        isSame = false;
    }

    if (input[leftPointer] !== input[rightPointer]) {
        isPalindrome = false;
    }

    leftPointer += 1;
    rightPointer -= 1;
}

console.log(
    isSame ? -1 :
    isPalindrome ? input.length - 1 :
    input.length
);
