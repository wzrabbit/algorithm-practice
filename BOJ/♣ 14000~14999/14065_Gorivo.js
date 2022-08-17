const input = parseFloat(require('fs').readFileSync(0, 'utf-8'));
console.log(3.785411784 * 100000 / (input * 1609.344));