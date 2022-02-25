const fs = require('fs');
const input = fs.readFileSync("/dev/stdin").toString().split('\n');
input.pop();
let result = '';

for (let i = 0; i < input.length; i++) {
    if (input[i].match(/[a-z]/g)) result += input[i].match(/[a-z]/g).join('').length + ' ';
    else result += '0 ';
    if (input[i].match(/[A-Z]/g)) result += input[i].match(/[A-Z]/g).join('').length + ' ';
    else result += '0 ';
    if (input[i].match(/[0-9]/g)) result += input[i].match(/[0-9]/g).join('').length + ' ';
    else result += '0 ';
    if (input[i].match(/ /g)) result += input[i].match(/ /g).join('').length + '\n';
    else result += '0\n';
}

result = result.slice(0, -1);
console.log(result);