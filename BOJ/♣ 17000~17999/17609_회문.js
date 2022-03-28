const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
let result = "";

for (let i = 0; i < input.length; i++) {
    let string = input[i];
    let leftResult = checkLeftSide(string);
    let rightResult = checkRightSide(string);

    if (leftResult === 0 && rightResult === 0) result += "0\n";
    else if (leftResult === 2 && rightResult === 2) result += "2\n";
    else result += "1\n";
}

result = result.slice(0, -1);
console.log(result);

function checkLeftSide(string) {
    let wrong = 0;
    let left = 0;
    let right = string.length - 1;

    while (left < right && wrong <= 1) {
        if (string[left] !== string[right]) {
            wrong++;
            if (string[left + 1] !== string[right]) {
                wrong = 2;
            }
            else {
                left += 2;
                right--;
            }
        }
        else {
            left++;
            right--;
        }
    }

    return wrong;
}

function checkRightSide(string) {
    let wrong = 0;
    let left = 0;
    let right = string.length - 1;

    while (left < right && wrong <= 1) {
        if (string[left] !== string[right]) {
            wrong++;
            if (string[left] !== string[right - 1]) {
                wrong = 2;
            }
            else {
                left++;
                right -= 2;
            }
        }
        else {
            left++;
            right--;
        }
    }

    return wrong;
}