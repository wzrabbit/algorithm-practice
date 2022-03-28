const input = require('fs').readFileSync('/dev/stdin').toString().trim();
let stack = [];
let ppap = 'PPAP';

for (let i = 0; i < input.length; i++) {
    stack.push(input[i]);
    if (input[i] === 'P') checkPPAP();
}

if (stack.length === 1 && stack[0] === 'P') console.log('PPAP');
else console.log('NP');

function checkPPAP() {
    if (stack.length < 4) return;
    let last = stack.length - 1;
    if (stack[last - 3] + stack[last - 2] + stack[last - 1] + stack[last] === 'PPAP') {
        stack.pop(); stack.pop(); stack.pop();
    }
    else return;
    checkPPAP();
}