const isPossible = (height) => {
  let totalTreeHeight = 0;

  trees.forEach((tree) => {
    totalTreeHeight += Math.max(tree - height, 0);
  });

  return totalTreeHeight >= need;
}

const getAnswer = () => {
  let start = 0;
  let end = 2_000_000_000;
  let mid;

  while (start <= end) {
    mid = Math.floor((start + end) / 2);

    if (isPossible(mid)) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return end;
}

const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const need = Number(input[0].split(' ')[1]);
const trees = input[1].split(' ').map(Number);

console.log(getAnswer());