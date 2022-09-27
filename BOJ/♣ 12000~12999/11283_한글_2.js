const hangul = require('fs').readFileSync(0, 'utf-8').toString().trim();
console.log(hangul.charCodeAt() - 44031);