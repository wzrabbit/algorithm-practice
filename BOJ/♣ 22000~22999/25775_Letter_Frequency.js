const input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n');
let db = Array.from(Array(31), () => Array(26).fill(0));
let maxLen = 0;
let printer = '';

for (let i = 1; i < input.length; i++) {
    const str = input[i];
    maxLen = Math.max(maxLen, str.length);

    for (let j = 0; j < input[i].length; j++) {
        db[j + 1][str[j].charCodeAt() - 97]++;
    }
}

for (let i = 1; i <= maxLen; i++) {
    let maxFreq = 1;
    let char = [];

    for (let j = 0; j < 26; j++) {
        if (db[i][j] > maxFreq) {
            char = [j];
            maxFreq = db[i][j];
        }
        else if (db[i][j] === maxFreq) {
            char.push(j);
        }
    }

    char = char.map(x => String.fromCharCode(x + 97));
    printer += `${i}: ${char.join(' ')}\n`;
}

console.log(printer);