const input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n');
let printer = '';
let isSet, text;

const checkSet = (start, end) => {
    if (isSet[start][end] !== '?')
        return isSet[start][end];

    if (start > end) {
        isSet[start][end] = true;
        return true;
    }

    if (/^.(,.)*$/.test(text.slice(start, end + 1))) {
        isSet[start][end] = true;
        return true;
    }

    if (text[start] === '{' && text[end] === '}' && checkSet(start + 1, end - 1)) {
        isSet[start][end] = true;
        return true;
    }

    for (let i = start + 1; i <= end - 1; i++) {
        if (text[i] !== ',') continue;
        if (checkSet(start, i - 1) && checkSet(i + 1, end)) {
            isSet[start][end] = true;
            return true;
        }
    }

    isSet[start][end] = false;
    return false;
}

for (let t = 1; t < input.length; t++) {
    text = input[t];
    let N = text.length;
    isSet = Array.from(Array(N), () => new Array(N).fill('?'));

    if (text[0] === '{' && text[N - 1] === '}' && checkSet(1, N - 2))
        printer += `Word #${t}: Set\n`;
    else
        printer += `Word #${t}: No Set\n`;
}

console.log(printer);