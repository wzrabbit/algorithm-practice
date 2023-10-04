const N = Number(require('fs').readFileSync(0, 'utf-8'));

const getNthFibonacciNumber = (n) => {
  if (n === 0) {
    return 0;
  }

  if (n === 1) {
    return 1;
  }

  return getNthFibonacciNumber(n - 1) + getNthFibonacciNumber(n - 2);
}

console.log(getNthFibonacciNumber(N));
