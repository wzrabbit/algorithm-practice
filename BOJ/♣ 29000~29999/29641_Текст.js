const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const limit = Number(input[0])
const words = input[1].split(/ +/);

let output = '';
let lineLength = 0;

for (let i = 0; i < words.length; i++) {
  if (lineLength === 0) {
    output += words[i];
    lineLength += words[i].length;
    continue;
  }

  if (lineLength + 1 + words[i].length > limit) {
    output += `\n${words[i]}`;
    lineLength = words[i].length;
    continue;
  }

  output += ` ${words[i]}`;
  lineLength += words[i].length + 1;
}

console.log(output);
