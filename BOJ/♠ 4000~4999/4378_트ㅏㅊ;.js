const input = require('fs').readFileSync('/dev/stdin').toString().replace(/\n$/, '').split('\n');
let printer = '';
const keyboard = [
  ['`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='],
  ['Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'],
  ['A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', "'"],
  ['Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/']
];

const getRealChar = (char) => {
  if (char === ' ') return ' ';
  for (let i = 0; i < 4; i++) {
    if (keyboard[i].indexOf(char) !== -1) return keyboard[i][keyboard[i].indexOf(char) - 1];
  }
};

for (let i = 0; i < input.length; i++) {
  const sentence = input[i];
  for (let j = 0; j < sentence.length; j++) {
    printer += getRealChar(sentence[j]);
  }
  printer += '\n';
}

console.log(printer);