const [_, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

let output = '';

input.forEach((sentence) => {
  output += `${(sentence.match(/P.*?L.*?U.*?/gi) || []).length}\n`;
});

console.log(output);
