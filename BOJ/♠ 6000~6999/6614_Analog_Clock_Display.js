function drawNeedle(angle) {
    const type = Math.floor(angle / 45);
    angle = angle % 90;
    if (angle > 45) angle = 90 - angle;
    const tan = Math.tan(angle / 180 * Math.PI);

    if ([0, 3, 4, 7].includes(type)) {
        for (let i = 0; i <= 22; i++) {
            let finalTan = Math.round(tan * i);
            let finalLen = i;

            if ([0, 7].includes(type))
                finalLen *= -1;

            if ([4, 7].includes(type))
                finalTan *= -1;

            needle[25 + finalLen][25 + finalTan] = 'X';
        }
    }
    else {
        for (let i = 0; i <= 22; i++) {
            let finalTan = Math.round(tan * i);
            let finalLen = i;

            if ([5, 6].includes(type))
                finalLen *= -1;

            if ([1, 6].includes(type))
                finalTan *= -1;

            needle[25 + finalTan][25 + finalLen] = 'X';
        }
    }
}

function decorateNeedle() {
    let r = 25;
    let c = 25;

    let dr = [-1, -1, -1, 0, 0, 1, 1, 1];
    let dc = [-1, 0, 1, -1, 1, -1, 0, 1];

    for (let i = 0; i <= 22; i++) {
        if (needle[r][c - 1] !== ' ' && needle[r][c + 1] !== ' ') {
            needle[r][c] = '-';
        }
        else if (needle[r - 1][c] !== ' ' && needle[r + 1][c] !== ' ') {
            needle[r][c] = '|';
        }
        else if (needle[r + 1][c - 1] !== ' ' && needle[r - 1][c + 1] !== ' ') {
            needle[r][c] = '/';
        }
        else if (needle[r + 1][c + 1] !== ' ' && needle[r - 1][c - 1] !== ' ') {
            needle[r][c] = '\\';
        }
        else
            needle[r][c] = 'o';

        for (let j = 0; j < 8; j++) {
            let nextR = r + dr[j];
            let nextC = c + dc[j];

            if (needle[nextR][nextC] === 'X') {
                r = nextR;
                c = nextC;
                break;
            }
        }
    }
}

function copyNeedle(len) {
    for (let r = 0; r < 51; r++) {
        for (let c = 0; c < 51; c++) {
            if (needle[r][c] !== ' ' && Math.abs(r - 25) ** 2 + Math.abs(c - 25) ** 2 <= len ** 2)
                clock[r][c] = needle[r][c];
        }
    }
}

function resetNeedle() {
    needle = Array.from(Array(51), () => new Array(51).fill(' '));
}

function resetClock() {
    clock = Array.from(Array(51), () => new Array(51).fill(' '));

    for (let r = 0; r < 51; r++) {
        if (r % 10 === 0) {
            clock[r][0] = '@';
            clock[r][50] = '@';
        }
        else {
            clock[r][0] = 'X';
            clock[r][50] = 'X';
        }
    }

    for (let c = 0; c < 51; c++) {
        if (c % 10 === 0) {
            clock[0][c] = '@';
            clock[50][c] = '@';
        }
        else {
            clock[0][c] = 'X';
            clock[50][c] = 'X';
        }
    }

    clock[2][24] = '1';
    clock[2][26] = '2';
    clock[25][2] = '9';
    clock[25][48] = '3';
    clock[48][25] = '6';
}

function printClock() {
    clock[25][25] = '*';

    for (let r = 0; r < 51; r++)
        printer += clock[r].join('') + '\n';
    printer += '\n';
}

function makeClock(time) {
    let [hour, minute] = time.split(':').map((x) => parseInt(x));
    hour %= 12;
    const hourAngle = hour * 30 + minute * 0.5;
    const minuteAngle = minute * 6;

    resetClock();

    resetNeedle();
    drawNeedle(hourAngle);
    decorateNeedle();
    copyNeedle(15);

    resetNeedle();
    drawNeedle(minuteAngle);
    decorateNeedle();
    copyNeedle(21);

    printClock();
}

const rl = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});
let input = '';
let clock, needle;
let printer = '';

rl.on('line', (line) => {
    input += line + '\n';
}).on('close', () => {
    input = input.trim().split('\n');

    for (let i = 0; i < input.length - 1; i++) {
        makeClock(input[i]);
    }

    console.log(printer);
});