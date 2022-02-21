const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();

while (input.indexOf("BUG") !== -1) {
    input = input.replace("BUG", "");
}
console.log(input);