let input = require('fs').readFileSync(0, 'utf-8').trim().split('').map(Number);
input = input.map((digit) => digit.toString(2).padStart(3, '0')).join('');
input = input.replace(/^0+/g, '');

if (input === '') {
  input = '0';
}

console.log(input);