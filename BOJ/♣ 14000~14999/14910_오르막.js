const input = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map((x) => parseInt(x));

let fail = false;
for (let i = 1; i < input.length; i++) {
    if (input[i] < input[i - 1]) {
        fail = true;
        break;
    }
}

if (fail) console.log('Bad');
else console.log('Good');