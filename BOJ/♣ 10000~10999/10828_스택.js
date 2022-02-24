const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const commandAmount = Number(input[0]);
let stack = [];
let currentCommand = [];
let result = "";

// Stack demonstration
for (let i = 1; i <= commandAmount; i++) {
    currentCommand = input[i].split(" ");
    
    // push?
    if (currentCommand[0] === "push") {
        stack[stack.length] = currentCommand[1];
    }
    // pop?
    else if (currentCommand[0] === "pop") {
        let pop = stack.pop();
        if (pop !== undefined) result += pop;
        else result += "-1";
    }
    // empty?
    else if (currentCommand[0] === "empty") {
        if (stack.length === 0) result += "1";
        else result += "0";
    }
    // top?
    else if (currentCommand[0] === "top") {
        if (stack.length !== 0) {
            result += stack[stack.length - 1];
        }
        else result += -1;
    }
    // size?
    else if (currentCommand[0] === "size") {
        result += stack.length;
    }
    // enter if the command is not push
    if (currentCommand[0] !== "push") result += "\n";
}

result = result.slice(result, -1);
console.log(result);