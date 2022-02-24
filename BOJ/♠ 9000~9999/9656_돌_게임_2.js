const input = parseInt(require('fs').readFileSync('/dev/stdin'));

if (input % 2 === 0) console.log('SK');
else console.log('CY');