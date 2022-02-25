const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let result = '';
let find = false;

for (let i = 0; i < 5; i++) {
    if ((/FBI/).test(input[i])) {
        result += (i + 1) + ' ';
        find = true;
    }
}

if (find === true) console.log(result);
else console.log('HE GOT AWAY!');