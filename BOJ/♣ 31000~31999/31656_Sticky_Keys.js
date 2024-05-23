const input = require('fs').readFileSync(0, 'utf-8');
const correctedMessage = input.replace(/(.)\1+/g, (matched) => matched[0]);

console.log(correctedMessage);
