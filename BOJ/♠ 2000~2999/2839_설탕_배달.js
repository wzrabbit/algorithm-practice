const fs = require("fs");
const input = parseInt(fs.readFileSync("/dev/stdin").toString().trim());
let searchNumber = input - (input % 5);
let foundResult = false;

while (foundResult === false) {
    if ((input - searchNumber) % 3 === 0) {
        console.log(parseInt(searchNumber / 5) + parseInt((input - searchNumber) / 3));
        foundResult = true;
    }
    else {
        if (searchNumber !== 0) {
            searchNumber -= 5;
        }
        else {
            console.log(-1);
            foundResult = true;
        }
    }
}