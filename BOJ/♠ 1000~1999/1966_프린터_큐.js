const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
let result = "";

for (let i = 0; i < input.length; i++) {
    input[i] = input[i].split(" ").map(Number);
}

for (let i = 0; i < input.length; i += 2) {
    let amount = input[i][0];
    let search = input[i][1];
    let important = input[i + 1];
    let printerQueue = [];
    let count = 0;
    let printSuccess = false;
    let maxImportant;

    for (let j = 0; j < amount; j++) {
        printerQueue.push(["X", important[j]]);
    }
    printerQueue[search][0] = "O";

    while (printSuccess === false) {
        maxImportant = 0;
        for (let k = 0; k < printerQueue.length; k++) {
            if (maxImportant < printerQueue[k][1]) maxImportant = printerQueue[k][1];
        }
        if (printerQueue[0][1] < maxImportant) printerQueue.push(printerQueue.shift());
        else {
            count++;
            if (printerQueue.shift()[0] === "O") {
                result += count + "\n";
                printSuccess = true;
            }
        }
    }
}

result = result.slice(0, -1);
console.log(result);
