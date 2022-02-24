const input = parseInt(require('fs').readFileSync('/dev/stdin'));
let cycle = ['SK', 'CY', 'SK', 'SK', 'SK', 'SK', 'CY'];

console.log(cycle[(input - 1) % 7]);