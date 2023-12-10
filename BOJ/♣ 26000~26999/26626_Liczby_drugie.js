const N = require('fs')
  .readFileSync(0, 'utf-8')
  .trim();

const isPrime = (num) => {
  if (num <= 1) {
    return false;
  }

  for (let i = 2; i * i <= num; i++) {
    if (num % i === 0) {
      return false;
    }
  }

  return true;
};

let isSuccess = false;

for (let i = 1; i < N.length; i++) {
  const left = N.slice(0, i);
  const right = N.slice(i);

  if (left[0] === '0' || right[0] === '0') {
    continue;
  }

  if (!isPrime(Number(left)) || !isPrime(Number(right))) {
    continue;
  }

  isSuccess = true;
  break;
}

console.log(isSuccess ? 'TAK' : 'NIE');
