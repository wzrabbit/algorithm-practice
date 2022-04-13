const input = require('fs').readFileSync('/dev/stdin').toString().trim();
let stack = [];
let opposite = {
    ')': '(', '}': '{', ']': '[',
    '(': ')', '{': '}', '[': ']'
};

for (let i = 0; i < input.length; i++) {
    if (['(', '{', '['].includes(input[i]))
        stack.push(input[i]);
    else if (opposite[input[i]] === stack[stack.length - 1])
        stack.pop();
    else
        stack.push(input[i]);
}

let produced = stack.join('');
if ((produced.match(/[)}\]][[({]/g) || []).length >= 2 ||
    (produced.match(/[[({][)}\]]/g) || []).length >= 1)
    console.log('NIE');
else {
    let left = '';
    let right = '';
    let openString = (produced.match(/[({[]+/) || [''])[0].split('').reverse();
    let closeString = (produced.match(/[\]})]+/) || [''])[0].split('').reverse();

    for (let i = 0; i < closeString.length; i++)
        left += opposite[closeString[i]];

    for (let i = 0; i < openString.length; i++)
        right += opposite[openString[i]];

    console.log(left + input + right);
}