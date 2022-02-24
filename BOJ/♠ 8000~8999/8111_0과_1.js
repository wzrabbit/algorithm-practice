const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((x) => parseInt(x));
const cases = parseInt(input[0]);
let mod;

for (let i = 1; i <= cases; i++) {
  let num = input[i];
  mod = new Array(num).fill(false);
  console.log(bfs(num));
}

function bfs(num) {
  mod[1] = true;
  let success = false;
  let queue = [[1, 1, 0]];
  let index = 0;
  while (index < queue.length) {
    [m, d, i] = queue[index];
    index++;
    if (mod[m * 10 % num] === false) {
      let calc = m * 10 % num;
      mod[calc] = true;
      queue.push([calc, 0, i * 2 + 1]);
      if (calc === 0) {
        success = true;
        break;
      }
    }
    if (mod[(m * 10 + 1) % num] === false) {
      let calc = (m * 10 + 1) % num;
      mod[calc] = true;
      queue.push([calc, 1, i * 2 + 2]);
      if (calc === 0) {
        success = true;
        break;
      }
    }
  }
  if (success === true) {
    const [_, lastDigit, lastIndex] = queue.pop();
    let result = [lastDigit];
    let parent = Math.floor((lastIndex - 1) / 2);
    for (let i = queue.length - 1; i >= 0; i--) {
      if (queue[i][2] === parent) {
        result.push(queue[i][1]);
        parent = Math.floor((parent - 1) / 2);
      }
    }
    return result.reverse().join('');
  }
  else {
    return 'BRAK';
  }
}