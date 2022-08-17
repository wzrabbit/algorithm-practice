const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let printer = '';

for (let i = 0; i < input.length; i++) {
    if (!['START', 'END', 'ENDOFINPUT'].includes(input[i])) {
        printer += input[i].replace(/[A-Z]/g, (x) => {
            return String.fromCharCode(((x.charCodeAt() - 70) + 26) % 26 + 65);
        });
        printer += '\n';
    }
}

console.log(printer);