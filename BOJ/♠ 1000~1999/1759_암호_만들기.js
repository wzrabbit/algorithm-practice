const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n')
const chooseLength = parseInt(input[0].split(' ')[0]);
const alphabets = input[1].split(' ');
alphabets.sort();
let visited = [];
let result = '';

alphabets.forEach((alphabet) => {
  dfs(alphabet);
});

function dfs(current) {
    visited.push(current);

    if (visited.length === chooseLength) {
      let con = 0;
      let vow = 0;
      visited.forEach((letter) => {
        if (['a', 'e', 'i', 'o', 'u'].includes(letter)) vow++;
        else con++;
      });
      if (con >= 2 && vow >= 1) {
        result += visited.join('') + '\n';
      }
      visited.pop();
      return;
    }

    alphabets.forEach((alphabet) => {
      if (!visited.includes(alphabet) && current < alphabet) {
        dfs(alphabet);
      }
    });

    visited.pop();
}

console.log(result);
