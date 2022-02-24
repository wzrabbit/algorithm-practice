const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let result = '';
input.pop();

for (let i = 0; i < input.length; i++) {
  if ((/NEMO/i).test(input[i])) {
    result += 'Found\n';
  }
  else result += 'Missing\n';
}

console.log(result);