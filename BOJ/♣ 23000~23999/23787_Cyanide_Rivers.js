const input = require('fs').readFileSync(0, 'utf-8').trim();
const zeroSizes = (input.match(/0+/g) || ['']).map(unit => unit.length);
console.log(Math.ceil(Math.max(...zeroSizes) / 2));
