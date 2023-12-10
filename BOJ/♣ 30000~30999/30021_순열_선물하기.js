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

const N = Number(require('fs').readFileSync(0));
const sum = N * (N + 1) / 2;
let output = '';

if (isPrime(sum)) {
  console.log('NO');
  return;
}

console.log('YES');

if (N % 4 === 1 || N % 4 === 2) {
  for (let i = 1; i <= N - 2; i += 2) {
    output += `${i} `;
  }

  for (let i = 2; i <= N; i += 2) {
    output += `${i} `;
  }

  output += N % 2 === 0 ? N - 1 : N;
} else {
  for (let i = 1; i <= N; i += 2) {
    output += `${i} `;
  }

  for (let i = 2; i <= N; i += 2) {
    output += `${i} `;
  }
}

console.log(output);

