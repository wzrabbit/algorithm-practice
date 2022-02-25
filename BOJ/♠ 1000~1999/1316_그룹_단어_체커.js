const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const cases = parseInt(input[0]);
let x = 'abcdefghijklmnopqrstuvwxyz';
let count = 0;

for (let i = 1; i <= cases; i++) {
    let success = true;
    word = input[i];
    for (let i = 0; i < 26; i++) {
        let regex = new RegExp(x[i] + '[^' + x[i] + ']+' + x[i]);
        if (regex.test(word)) {
            success = false;
        }
    }
    if (success) count++;
}

console.log(count);