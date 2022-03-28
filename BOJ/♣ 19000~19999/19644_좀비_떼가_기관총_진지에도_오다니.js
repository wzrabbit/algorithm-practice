let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const road = parseInt(input[0]);
const [range, power] = input[1].split(' ').map(Number);
let item = parseInt(input[2]);
const maxPower = range * power;
let damage = power;
let itemHistory = [];
let historyIndex = 0;
let result = 'YES';
input[0] = input[1] = input[2] = -1;
input = input.map(Number);

for (let i = 3; i < road + 3; i++) {
    if (historyIndex < itemHistory.length && i === itemHistory[historyIndex]) historyIndex++;
    if (input[i] - damage + (itemHistory.length - historyIndex) * power > 0) {
        if (item > 0) {
            item--;
            itemHistory.push(i + range);
        }
        else {
            result = 'NO';
            break;
        }
    }
    if (damage < maxPower) damage += power;
}

console.log(result);