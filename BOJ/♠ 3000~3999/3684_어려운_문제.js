const [T, ...numbers] = require('fs').readFileSync(0, 'utf-8').trim().split('\n').map(Number);

for (let a = 0; a <= 10000; a += 1) {
  for (let b = 0; b <= 10000; b += 1) {
    let success = true;

    for (let i = 0; i < T - 1; i += 1) {
      if (((numbers[i] * a + b) % 10001 * a + b) % 10001 !== numbers[i + 1]) {
        success = false;
        break;
      }
    }

    if (success) {
      for (let i = 0; i < T; i += 1) {
        console.log((numbers[i] * a + b) % 10001);
      }
      return;
    }
  }
}
