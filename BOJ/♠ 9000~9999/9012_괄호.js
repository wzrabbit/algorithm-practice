const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
let stack = [];
let result = "";
let error = false;

for (let i = 0; i < input.length; i++) {
    let text = input[i];
    for (let j = 0; j < text.length; j++) {
        addStack(text[j]);
        if (error === true) break;
    }
    if (stack.length === 0 && error === false) result += "YES\n";
    else result += "NO\n";
    stack = [];
    error = false;
}

result = result.substr(0, result.length - 1) // remove last enter
console.log(result);

// stack
function addStack(symbol) {
    if (symbol === "(") {
        stack[stack.length] = "(";
    }
    else if (stack[stack.length - 1] === "(") {
        stack.pop();
    }
    else error = true; // stop algorithm if error found
}