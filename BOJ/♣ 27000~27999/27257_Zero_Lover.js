const number = require('fs').readFileSync(0, 'utf-8').trim();
console.log(number.replace(/0+$/, '').replace(/[^0]/g, '').length);