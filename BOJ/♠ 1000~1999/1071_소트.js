const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n')[1].split(' ').map((x) => parseInt(x)).sort((a, b) => a - b);
let arr = [input[0]];
let temp = [];

for (let i = 1; i < input.length; i++) {
    let last = arr[arr.length - 1];
    if (input[i] === last + 1) {
        temp.push(input[i]);
    }
    else {
        arr.push(input[i]);
        while (temp.length > 0) {
            arr.push(temp.pop());
        }
    }
}

let index = arr.length - 1;
if (temp.length > 0) {
    let key = temp[0] - 1;
    while (arr[index] === key && index >= 0) {
        index--;
    }
    arr = [...arr.slice(0, index + 1), ...temp, ...arr.slice(index + 1, arr.length)];
}

console.log(arr.join(' '));