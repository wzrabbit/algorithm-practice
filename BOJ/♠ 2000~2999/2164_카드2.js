const fs = require("fs");
const input = parseInt(fs.readFileSync("/dev/stdin"));
let cardBox = [...Array(input + 1).keys()];
let cardBoxStart = 1;

for (let i = 0; i < input - 1; i++) {
    cardBoxStart++;
    cardBox.push(cardBox[cardBoxStart]);
    cardBoxStart++;
}

console.log(cardBox[cardBoxStart]);
