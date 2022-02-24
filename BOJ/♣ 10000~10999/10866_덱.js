const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const commandAmount = Number(input[0]);
let deque = [];
let currentCommand = [];
let result = "";

// Deque demonstration
for (let i = 1; i <= commandAmount; i++) {
    currentCommand = input[i].split(" ");
    
    // push_front?
    if (currentCommand[0] === "push_front") {
        deque[deque.length] = currentCommand[1];
    }
    // push_back?
    else if (currentCommand[0] === "push_back") {
        deque.unshift(currentCommand[1]);
    }
    // pop_front
    else if (currentCommand[0] === "pop_front") {
        if (deque.length !== 0) result += deque.pop();
        else result += "-1";
    }
    // pop_back
    else if (currentCommand[0] === "pop_back") {
        if (deque.length !== 0) result += deque.shift();
        else result += "-1";
    }
    // empty?
    else if (currentCommand[0] === "empty") {
        if (deque.length === 0) result += "1";
        else result += "0";
    }
    // front?
    else if (currentCommand[0] === "front") {
        if (deque.length !== 0) {
            result += deque[deque.length - 1];
        }
        else result += -1;
    }
    // back?
    else if (currentCommand[0] === "back") {
        if (deque.length !== 0) {
            result += deque[0];
        }
        else result += -1;
    }
    // size?
    else if (currentCommand[0] === "size") {
        result += deque.length;
    }
    // enter if the command is not push
    if (currentCommand[0] !== "push_front" && currentCommand[0] !== "push_back") result += "\n";
    
}

result = result.slice(result, -1);
console.log(result);