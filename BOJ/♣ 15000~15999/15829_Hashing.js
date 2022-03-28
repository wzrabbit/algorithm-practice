const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
input = input.toString();
let sum = 0;

for (let i = 0; i < input.length; i++) {
    sum += getValue(input[i], i + 1);
    sum = sum % 1234567891;
}

console.log(sum);

function getValue(alphabet, pow) {
    alphabet = alphabet.charCodeAt() - 96;

    for (let i = 1; i < pow; i++) {
        alphabet *= 31;
        alphabet = alphabet % 1234567891;
    }
    return alphabet;
}