let input = require('fs').readFileSync('/dev/stdin').toString().trim();
let result = 0;
input = input.replace(/^.*?-|^[^-]*$/, (x) => {
    let nums = (x.endsWith('-') ? x.slice(0, -1) : x).split('+');
    nums.forEach((y) => {
        result += parseInt(y);
    });
    return '';
});
input = input.split(/[-+]/);
input.forEach((x) => {
    result += Math.abs(x) * -1;
});
console.log(result);