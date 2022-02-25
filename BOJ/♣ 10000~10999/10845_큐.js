const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const commandAmount = Number(input[0]);
let queue = [];
let currentCommand = [];
let result = "";

// Queue demonstration
for (let i = 1; i <= commandAmount; i++) {
    currentCommand = input[i].split(" ");

    // push?
    if (currentCommand[0] === "push") {
        queue[queue.length] = currentCommand[1];
    }
    // pop?
    else if (currentCommand[0] === "pop") {
        if (queue.length !== 0) result += queue.shift();
        else result += "-1";
    }
    // empty?
    else if (currentCommand[0] === "empty") {
        if (queue.length === 0) result += "1";
        else result += "0";
    }
    // front?
    else if (currentCommand[0] === "front") {
        if (queue.length !== 0) {
            result += queue[0];
        }
        else result += -1;
    }
    // back?
    else if (currentCommand[0] === "back") {
        if (queue.length !== 0) {
            result += queue[queue.length - 1];
        }
        else result += -1;
    }
    // size?
    else if (currentCommand[0] === "size") {
        result += queue.length;
    }
    // enter if the command is not push
    if (currentCommand[0] !== "push") result += "\n";
}

result = result.slice(result, -1);
console.log(result);