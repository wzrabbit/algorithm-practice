const input = parseInt(require('fs').readFileSync('/dev/stdin'));
console.log(parseInt(input / 5) + parseInt(input / 25) + parseInt(input / 125));