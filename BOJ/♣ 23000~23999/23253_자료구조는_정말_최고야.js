const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const books = parseInt(input[0].split(' ')[0]);
let stacks = [];
let dp = Array(books + 1).fill(-1);
let result = '';

for (let i = 2; i < input.length; i += 2) {
    let pile = input[i].split(' ').map(Number);
    stacks.push(pile);
    dp[pile[pile.length - 1]] = i / 2 - 1;
}

let success = true;
for (let i = 1; i <= books; i++) {
    if (dp[i] !== -1) {
        stacks[dp[i]].pop();
        if (stacks[dp[i]].length >= 1) {
            dp[stacks[dp[i]][stacks[dp[i]].length - 1]] = dp[i];
        }
    }
    else {
        success = false;
        break;
    }
}

if (success === false) console.log('No');
else console.log('Yes');