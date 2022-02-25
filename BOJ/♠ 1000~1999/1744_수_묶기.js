const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map(Number);
const cases = parseInt(input[0]);
input[0] = -9999;
input.sort((a, b) => b - a);
input.pop();

sum = 0;
index = 0;

while (input[index] > 0) {
    if (index === input.length - 1) {
        sum += input[index];
        break;
    }
    else if (index > input.length - 1) {
        break;
    }

    let c = input[index];
    let n = input[index + 1];

    if (c === 1) {
        if (n === 1) {
            sum += 1;
            index++;
        }
        else if (n <= 0) {
            sum += 1;
            break;
        }
    }
    else {
        if (n === 1) {
            sum += c;
            index++;
        }
        else if (n < 0) {
            sum += c;
            break;
        }
        else {
            sum += c * n;
            index += 2;
        }
    }
}

index = input.length - 1;
while (input[index] < 0) {
    if (index === 0) {
        sum += input[index];
        break;
    }
    else if (index < 0) {
        break;
    }

    let c = input[index];
    let n = input[index - 1];

    if (n > 0) {
        sum += c;
        break;
    }
    else if (n === 0) {
        break;
    }
    else {
        sum += c * n;
        index -= 2;
    }
}

console.log(sum);