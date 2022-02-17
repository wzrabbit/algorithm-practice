let fs = require("fs");
let input = parseInt(fs.readFileSync("/dev/stdin"));
let success = false;

for (let i = 1; i <= 1000000; i++) {
    let sum = i;
    for (let j = 0; j < i.toString().length; j++) {
        sum += Number(i.toString()[j]);
    }
    if (sum === input) {
        success = true;
        console.log(i);
        break;
    }
}

if (success === false) console.log(0);