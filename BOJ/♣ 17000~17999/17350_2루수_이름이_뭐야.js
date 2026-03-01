const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');

if (input.includes('anj')) {
  console.log('뭐야;');
} else {
  console.log('뭐야?');
}
