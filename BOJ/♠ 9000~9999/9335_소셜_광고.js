const solve = () => {
  const N = Number(input[index++]);
  const friendInfos = [[]];
  let answer = N;

  for (let i = 0; i < N; i++) {
    const friendInfo = input[index++]
      .split(' ')
      .slice(1)
      .map(Number);

    friendInfos.push(friendInfo);
  };

  for (let i = 1; i < (1 << N); i++) {
    const binary = i.toString(2).padStart(N + 1, '0');
    const isViewed = new Array(N + 1).fill(false);
    let publishCount = 0;

    for (let j = 1; j <= N; j++) {
      if (binary[j] === '0') {
        continue;
      }

      publishCount += 1;
      isViewed[j] = true;

      friendInfos[j].forEach((friendInfo) => {
        isViewed[friendInfo] = true;
      });
    }

    let success = true;

    for (let i = 1; i <= N; i++) {
      if (!isViewed[i]) {
        success = false;
        break;
      }
    }

    if (success) {
      answer = Math.min(answer, publishCount);
    }
  }

  return answer;
};

const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const T = Number(input[0]);
let index = 1;
let output = '';

for (let i = 0; i < T; i++) {
  output += `${solve()}\n`;
}

console.log(output);
