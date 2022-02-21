const input = require('fs').readFileSync('/dev/stdin').toString().trim();
search = input.match(/[A-z-]+/g);
search.sort((a, b) => b.length - a.length);

if (search[0] === 'E-N-D') {
  console.log(search[1].toLowerCase());
}
else {
  console.log(search[0].toLowerCase());
}