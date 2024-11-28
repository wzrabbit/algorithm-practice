const input = require('fs').readFileSync(0, 'utf-8').trim();

if (/^([1-9]\d*)\+(\1)$/.test(input)) {
  console.log('CUTE');
} else {
  console.log('No Money');
}
