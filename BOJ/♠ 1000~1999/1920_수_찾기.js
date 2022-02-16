const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
let result = "";
const targetList = input[0].split(" ").map(Number);
const repeat = parseInt(input[1]);
const searchList = input[2].split(" ").map(Number);
targetList.sort((a, b) => a - b);

for (let i = 0; i < searchList.length; i++) {
    let left = 0;
    let right = targetList.length - 1;
    let success = false;

    while (left <= right && success === false) {
      let mid = Math.floor((left + right) / 2);

      if (searchList[i] === targetList[mid]) {
        result += "1\n";
        success = true;
      }
      else if (searchList[i] > targetList[mid]) {
        left = mid + 1; 
      }
      else {
        right = mid - 1;
      }
    }
    if (success === false) result += "0\n";
}

console.log(result);
