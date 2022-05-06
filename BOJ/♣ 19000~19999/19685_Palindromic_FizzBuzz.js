let [repeat, str] = require('fs').readFileSync('/dev/stdin').toString().split(' ');
repeat = parseInt(repeat);
let memory = [str];
let idx = 1;

function transform(str) {
    let newStr = '';
    let [l, r] = [0, str.length - 1];

    while (l <= r) {
        if (l === r) {
            newStr += str[l];
            break;
        }

        newStr += str[l];
        newStr += str[r];
        l++; r--;
    }

    memory.push(newStr);
}

while (memory[0] !== memory[idx]) {
    transform(memory[memory.length - 1]);
    idx++;
}

console.log(memory[repeat % (idx + 1)]);
