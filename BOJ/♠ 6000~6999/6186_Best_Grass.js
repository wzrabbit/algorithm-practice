let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const row = input[0].split(' ')[0];
const column = input[1].split(' ')[1];
let grass = 0;
input.shift();

for (let i = 0; i < input.length; i++) {
  input[i] = input[i].split('');
}

for (let row = 0; row < input.length; row++) {
  for (let col = 0; col < input[0].length; col++) {
    if (input[row][col] === '#') {
      grass++;
      input[row][col] = '.';
      try { if (input[row - 1][col] !== undefined || input[row - 1][col] === '#') input[row - 1][col] = '.'; } catch(e) {}
      try { if (input[row + 1][col] !== undefined || input[row + 1][col] === '#') input[row + 1][col] = '.'; } catch(e) {}
      try { if (input[row][col - 1] !== undefined || input[row][col - 1] === '#') input[row][col - 1] = '.'; } catch(e) {}
      try { if (input[row][col + 1] !== undefined || input[row][col + 1] === '#') input[row][col + 1] = '.'; } catch(e) {}
    }
  }
}

console.log(grass);
