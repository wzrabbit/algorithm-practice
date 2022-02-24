const input = parseInt(require('fs').readFileSync('/dev/stdin'));

if (input % 2 === 0) console.log('CY');
else console.log('SK');