const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
input.pop();
let result = '';

for (let i = 0; i < input.length; i++) {
    let word = input[i];
    let stack = [];
    let rst = false;

    if (/<[^/A-z0-9]/.test(word)) rst = true;
    word = word.replace(/<[A-z0-9]+ ?\/>/g, '');

    word = word.replace(/<\/?[A-z0-9]+>|<\w+ \w+="[^<>]*">/g, (tag) => {
        if (tag.startsWith('</')) {
            if (stack.pop() !== tag.replace(/[/<>]/g, '')) {
                rst = true;
            }
        }
        else stack.push(tag.replace(/[<>]| \w+="[^<>]*">/g, ''));
        return '';
    });

    if (/[/<>]/.test(word)) rst = true;
    if (rst || stack.length) result += 'illegal\n';
    else result += 'legal\n';
}

console.log(result);