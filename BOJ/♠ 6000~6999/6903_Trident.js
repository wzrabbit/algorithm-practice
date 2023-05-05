const [tine, space, handle] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n')
  .map(Number);

let trident = '';
const width = space * 2 + 3;

for (let i = 0; i < tine; i += 1) {
  trident += '*' + ' '.repeat(space) + '*' + ' '.repeat(space) + '*\n';
}

trident += '*'.repeat(width) + '\n';

for (let i = 0; i < handle; i++) {
  trident += ' '.repeat(Math.floor(width / 2)) + '*\n';
}

console.log(trident);
