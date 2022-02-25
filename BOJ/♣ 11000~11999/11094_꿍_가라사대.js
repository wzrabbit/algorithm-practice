const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let result = '';
input.shift();

for (let i = 0; i < input.length; i++) {
    if ((/^Simon says/).test(input[i])) {
        result += input[i].replace('Simon says', '') + '\n';
    }
}

console.log(result);