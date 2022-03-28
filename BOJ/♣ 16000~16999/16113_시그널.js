let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const frag = parseInt(input[0]) / 5;
input.shift();
input = input.toString();

let signal = [];
let result = '';
for (let i = 0; i < frag; i++) {
    signal.push(input[i] + input[i + frag] + input[i + frag * 2] + input[i + frag * 3] + input[i + frag * 4]);
}

let index = 0;
while (index < signal.length) {
    // Space
    if (signal[index] === '.....') {
        index++;
        continue;
    }
    // 0, 1, 6, 8
    if (signal[index] === '#####') {
        index++;
        if (signal[index] === '#...#') {
            index += 3;
            result += '0';
        }
        else if (signal[index] === '.....' || signal[index] === undefined) {
            index += 1;
            result += '1';
        }
        else if (signal[index] === '#.#.#') {
            index += 1;
            if (signal[index] === '#.###') {
                index += 2;
                result += '6';
            }
            else {
                index += 2;
                result += '8';
            }
        }
        continue;
    }
    // 5, 9
    if (signal[index] === '###.#') {
        index += 2;
        if (signal[index] === '#.###') {
            index += 2;
            result += '5';
        }
        else {
            index += 2;
            result += '9';
        }
        continue;
    }
    // 2
    if (signal[index] === '#.###') {
        index += 4;
        result += '2';
        continue;
    }
    // 3
    if (signal[index] === '#.#.#') {
        index += 4;
        result += '3';
        continue;
    }
    // 4
    if (signal[index] === '###..') {
        index += 4;
        result += '4';
        continue;
    }
    // 7
    if (signal[index] === '#....') {
        index += 4;
        result += '7';
        continue;
    }
}

console.log(result);
