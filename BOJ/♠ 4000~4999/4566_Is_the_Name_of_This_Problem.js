const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let printer = '';

for (let i = 0; i < input.length - 1; i++) {
  if (/^"([^"]+)" \1$/.test(input[i])) printer += 'Quine(' + input[i].match(/(?<=")[^"]+(?=")/) + ')\n';
  else printer += 'not a quine\n';
}

console.log(printer);