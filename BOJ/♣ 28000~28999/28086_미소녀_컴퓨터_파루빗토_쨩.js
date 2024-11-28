const input = require('fs').readFileSync(0, 'utf-8').trim();
const operator = input.match(/[/*]-|[+*/]|(?<=.)-/)[0];
let [num1, num2] = input.match(/^-\d+|\d+/g);

num1 = parseInt(num1, 8);
num2 = parseInt(num2, 8);
let result;

switch (operator) {
  case '+':
    result = num1 + num2;
    break;
  case '-':
    result = num1 - num2;
    break;
  case '*':
    result = BigInt(num1) * BigInt(num2);
    break;
  case '/':
    result = Math.floor(num1 / num2);
    break;
  case '*-':
    result = BigInt(num1) * -BigInt(num2);
    break;
  case '/-':
    result = Math.floor(num1 / -num2);
    break;
}

console.log((result === Infinity || isNaN(Number(result))) ? 'invalid' : result.toString(8));
