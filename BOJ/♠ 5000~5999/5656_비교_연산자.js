const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
let output = '';

for (let i = 0; i < input.length; i++) {
  const line = input[i];

  if (line.includes('E')) {
    break;
  }

  output += `Case ${i + 1}: ${eval(line)}\n`;
}

console.log(output);
