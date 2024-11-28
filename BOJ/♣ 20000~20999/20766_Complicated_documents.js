const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const N = Number(input[0]);
const lines = input.slice(1);
let output = '';

lines.forEach((line) => {
  let result = line;

  for (let i = 0; i < 2; i++) {
    result = result.replace(/[^ ]:/g, (matched) => `${matched[0]} ${matched[1]}`);
    result = result.replace(/:[^ ]/g, (matched) => `${matched[0]} ${matched[1]}`);
    result = result.replace(/[^ ]-/g, (matched) => `${matched[0]} ${matched[1]}`);
    result = result.replace(/-[^ ]/g, (matched) => `${matched[0]} ${matched[1]}`);
  }

  output += `${result}\n`;
});

console.log(output);
