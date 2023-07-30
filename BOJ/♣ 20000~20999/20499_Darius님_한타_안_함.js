const [K, D, A] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split(' ')
  .map(Number);

if (K + A < D || D === 0) {
  console.log('hasu');
} else {
  console.log('gosu');
}