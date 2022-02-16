let stick = parseInt(require('fs').readFileSync('/dev/stdin'));
stick = stick.toString(2);
console.log((stick.match(/1/g) || []).length);