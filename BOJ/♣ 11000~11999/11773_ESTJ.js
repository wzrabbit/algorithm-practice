function plus(level) {
    if (++word[level] === 26) {
        word[level] = 0;
        plus(level - 1);
    }
}

function getWord() {
    plus(3);
    return alphabet[word[0]] + alphabet[word[1]] + alphabet[word[2]] + alphabet[word[3]];
}

const rl = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

const alphabet = 'abcdefghijklmnopqrstuvwxyz';
let word = [0, 0, 0, 0];
let printer = '';

rl.on('line', function (line) {
    const len = parseInt(line.split(' ')[0]);

    for (let i = 0; i < len; i++)
        printer += getWord() + ' ';
    printer = printer.slice(0, -1);

    console.log(printer);
    rl.close();
}).on("close", function () {
    process.exit();
});