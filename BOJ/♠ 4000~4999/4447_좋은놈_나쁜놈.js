const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let printer = '';

for (let i = 1; i < input.length; i++) {
  const word = input[i];
  const gCount = (word.match(/g/gi) || []).length;
  const bCount = (word.match(/b/gi) || []).length;
  printer += word + ' is ';
  if (gCount > bCount) printer += 'GOOD\n';
  else if (gCount < bCount) printer += 'A BADDY\n';
  else printer += 'NEUTRAL\n';
}

console.log(printer);