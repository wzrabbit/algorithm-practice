const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
let nop = 0;

input = input.replace(/[A-Z][a-z]*$/, "");

input = input.replace(/[A-Z][a-z]*/g, (word) => {
    nop += (word.length % 4 === 0) ? 0 : 4 - (word.length % 4);
    return "";
});

console.log(nop);