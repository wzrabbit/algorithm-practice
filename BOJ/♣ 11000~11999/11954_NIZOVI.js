const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

rl.on('line', function (line) {
    const input = line.trim().split('');

    let indent = 0;

    for (let i = 0; i < input.length; i++) {
        if (i >= 1 && input[i - 1].includes(',') && input[i] === '{') {
            input[i] = '{\n';
            indent += 2;
        }
        else if (input[i] === '{') {
            input[i] = ' '.repeat(indent) + '{\n';
            indent += 2;
        }
        else if (input[i] === '}') {
            indent -= 2;
            if (input[i + 1] === ',') input[i] = ' '.repeat(indent) + '}'
            else input[i] = ' '.repeat(indent) + '}\n';
        }
        else if (input[i] === ',') {
            input[i] = ',\n' + ' '.repeat(indent);
        }

        if (i >= 1 && input[i - 1].includes('{') && /[A-z]/.test(input[i])) {
            input[i] = ' '.repeat(indent) + input[i];
        }
        if (input[i + 1] === '}' && /[A-z]/.test(input[i])) {
            input[i] = input[i] + '\n';
        }
    }

    console.log(input.join(''));

    rl.close();
}).on('close', function () {
    process.exit();
});