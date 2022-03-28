const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

let max_ = 0;
for (let i = 1; i < input.length; i++) {
    max_ = Math.max(max_, (input[i].match(/while|for/g) || []).length);
}

console.log(max_);