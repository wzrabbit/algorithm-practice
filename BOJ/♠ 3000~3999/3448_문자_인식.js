const input = require('fs').readFileSync('/dev/stdin').toString().trim().replace(/^\d+\n/g, '').
    split('\n\n').map((x) => x.replace(/\n/g, ''));
let printer = '';

for (let i = 0; i < input.length; i++) {
    const sharp = (input[i].match(/#/g) || []).length;
    const all = input[i].length;
    const calc = Math.round((all - sharp) / all * 1000) / 10;
    printer += `Efficiency ratio is ${calc}%.\n`;
}

console.log(printer);