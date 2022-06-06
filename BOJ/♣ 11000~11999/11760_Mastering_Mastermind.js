const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let textA, textB;

rl.on('line', function (line) {
    [_, textA, textB] = line.split(' ').map((x) => x.split(''));
}).on('close', function () {
    let strike = 0;
    let ball = 0;

    for (let i = 0; i < textA.length; i++) {
        if (textA[i] === textB[i]) {
            textA[i] = '_';
            textB[i] = '-';
            strike++;
        }
    }

    for (let i = 0; i < textA.length; i++) {
        let search = textA[i];

        for (let j = 0; j < textA.length; j++) {
            if (textB[j] === search) {
                textA[j] = '_';
                textB[j] = '-';
                ball++;
                break;
            }
        }
    }

    console.log(strike, ball);
});

