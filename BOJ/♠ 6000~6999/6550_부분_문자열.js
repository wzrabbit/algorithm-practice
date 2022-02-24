let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
for (let i = 0; i < input.length; i++) {
  input[i] = input[i].split(' ');
}
let result = '';

for (let i = 0; i < input.length; i++) {
  let wordIndex = 0;
  const [search, whole] = input[i];
  for (let j = 0; j < whole.length; j++) {
    if (whole[j] === search[wordIndex]) wordIndex++;
  }
  if (wordIndex >= search.length) result += 'Yes\n';
  else result += 'No\n';
}

console.log(result);