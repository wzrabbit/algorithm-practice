let input = require('fs').readFileSync('/dev/stdin').toString().trim();
let len = 0;
let result = '';

input = input.replace(/\n|\t/g, ' ').replace(/ {2,}/g, ' ');
input = input.split(' ');

for (let i = 0; i < input.length; i++) {
  if (input[i] === '<br>') {
    if (len !== 0) result = result.slice(0, -1);
    result += '\n';
    len = 0;
  }
  else if (input[i] === '<hr>') {
    if (len !== 0) result = result.slice(0, -1) + '\n';
    result += '----------'.repeat(8) + '\n';
    len = 0;
  }
  else if (len + input[i].length <= 80) {
    result += input[i] + ' ';
    len += input[i].length + 1;
  }
  else {
    result = result.slice(0, -1) + '\n';
    result += input[i] + ' ';
    len = input[i].length + 1;
  }
}

if (len !== 0) result = result.slice(0, -1);
console.log(result);