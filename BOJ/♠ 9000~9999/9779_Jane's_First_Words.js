const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

let output = '';

input.forEach((line) => {
  output += /^da+dd?(i|y)$/.test(line) ? 'She called me!!!\n' : 'Cooing\n';
});

console.log(output);
