let input = require('fs').readFileSync('/dev/stdin').toString().trim();
input = input.replace(/<.*?>|[^ <>]+/g, (x) => {
    if (x[0] !== '<') x = x.split('').reverse().join('');
    return x;
});

console.log(input);