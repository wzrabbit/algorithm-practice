const input = require('fs').readFileSync('/dev/stdin').toString().split('\n')
let printer = '';

function check(text) {
    if (!/^<HTML><BODY>.*<\/BODY><\/HTML>$/.test(text))
        return false;
    text = text.replace('<HTML><BODY>', '').replace('</BODY></HTML>', '');

    let stack = [];
    text = text.replace(/<\/?[^<>]*>/g, (matched) => {
        if (matched === '<B>' || matched === '<I>') {
            stack.push(matched[1]);
        }
        else if (/^<\/[ABI]>$/.test(matched)) {
            let closeTag = matched.replace(/<\/|>/g, '');

            if (stack.length >= 1 && closeTag === stack[stack.length - 1])
                stack.pop();
            else
                stack.push('FAIL');
        }
        else if (/^<A.*>/.test(matched)) {
            if (/^<A HREF=http:\/\/[^ <>]+.com/.test(matched))
                stack.push('A');
            else
                stack.push('FAIL');
        }
        else
            stack.push('FAIL');

        return '';
    });

    if (stack.length !== 0)
        return false;

    if (/[<>]/.test(text))
        return false;

    return true;
}

for (let i = 1; i < input.length - 1; i++) {
    if (check(input[i]))
        printer += 'Syntax Included\n';
    else
        printer += 'No Syntax Included\n';
}

console.log(printer);