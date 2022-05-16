let [n, ...input] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let average = 0;
let mul = 1;
let valid = true;

const fail = [
    [[1], [1, 4], []],
    [[1, 2, 3, 7], [0, 1, 2, 3, 4, 5, 6, 7, 8, 9], [5, 6]],
    [[1, 7], [0, 1, 7], []],
    [[1, 3, 4, 5, 7, 9], [0, 1, 2, 3, 4, 5, 6, 7, 8, 9], [2]],
    [[1, 4, 7], [1, 4, 7], []]
];

for (let i = 0; i < 5; i++)
    input[i] = input[i].split('');

for (let i = 0; i < n; i++) {
    let current = [[], [], [], [], []];
    let isPossible = new Array(10).fill(true);
    let possibleCount = 0;
    let currentAvg = 0;

    for (let j = 0; j < 5; j++) {
        for (let k = 0; k < 3; k++)
            current[j].unshift(input[j].pop());
    }

    for (let j = 0; j < 5; j++) {
        for (let k = 0; k < 3; k++) {
            if (current[j][k] === '#') {
                for (let l = 0; l < fail[j][k].length; l++)
                    isPossible[fail[j][k][l]] = false;
            }
        }
    }

    for (let j = 0; j < 10; j++) {
        if (isPossible[j]) {
            possibleCount++;
            currentAvg += j * mul;
        }
    }

    if (possibleCount === 0) {
        valid = false;
        break;
    }

    if (i !== n - 1) {
        for (let i = 0; i < 5; i++)
            input[i].pop();
    }

    average += (currentAvg / possibleCount);
    mul *= 10;
}

if (valid)
    console.log(average);
else
    console.log(-1);