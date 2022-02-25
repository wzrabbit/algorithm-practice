const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
input.pop();
let result = '';

for (let i = 0; i < input.length; i++) {
    let stack = [];
    let sentence = input[i].replace(/[^{}()[\]]/g, '');
    let error = false;

    for (let j = 0; j < sentence.length; j++) {
        if (['(', '{', '['].includes(sentence[j])) stack.push(sentence[j]);
        else if (!(sentence[j] === '}' && stack[stack.length - 1] === '{' || sentence[j] === ')' && stack[stack.length - 1] === '(' || sentence[j] === ']' && stack[stack.length - 1] === '[')) {
            error = true;
            break;
        }
        else stack.pop();
    }

    if (error || stack.length !== 0) result += 'Illegal\n';
    else result += 'Legal\n';
}

console.log(result);