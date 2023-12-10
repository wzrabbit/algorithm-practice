const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim();

console.log((input.match(/joke/g) || []).length);
