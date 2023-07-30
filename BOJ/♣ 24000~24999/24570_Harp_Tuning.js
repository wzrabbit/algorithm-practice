const input = require('fs').readFileSync('/dev/stdin').toString().trim().match(/\w+[-+]\d+/g);
let printer = '';

for (let i = 0; i < input.length; i++) {
    const [tune, dir, amount] = input[i].match(/\w+|\d+|[-+]/g);

    printer += tune + ' ' + ((dir === '+') ? 'tighten' : 'loosen') + ' ' + amount + '\n';
}

console.log(printer);