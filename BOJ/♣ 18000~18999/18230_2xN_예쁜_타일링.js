const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let space = parseInt(input[0]);
let one = input[1].split(' ').map((x) => parseInt(x)).sort((a, b) => a - b);
let two = input[2].split(' ').map((x) => parseInt(x)).sort((a, b) => a - b);
let total = 0;

if (space % 2 === 1) {
    space -= 1;
    total += one.pop();
}

while (space > 0) {
    if (one.length < 2) {
        total += two.pop();
    }
    else if (two.length === 0) {
        total += one.pop() + one.pop();
    }
    else {
        if (two[two.length - 1] > one[one.length - 1] + one[one.length - 2]) {
            total += two.pop();
        }
        else {
            total += one.pop() + one.pop();
        }
    }
    space -= 2;
}

console.log(total);