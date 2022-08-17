let word = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
word.shift();
const engToMin = {
    a: 'a', b: 'b', c: 'k', d: 'd', e: 'e', f: 'g', g: 'h', h: 'i', i: 'l', j: 'm',
    k: 'n', l: 'ng', m: 'o', n: 'p', o: 'r', p: 's', q: 't', r: 'u', s: 'w', t: 'y'
}
const minToEng = {
    a: 'a', b: 'b', k: 'c', d: 'd', e: 'e', g: 'f', h: 'g', i: 'h', l: 'i', m: 'j',
    n: 'k', ng: 'l', o: 'm', p: 'n', r: 'o', s: 'p', t: 'q', u: 'r', w: 's', y: 't'
}

word = word.map((x) => x.replace(/ng|[a-z]/g, (y) => {
    return minToEng[y];
}));

word.sort();

word = word.map((x) => x.replace(/./g, (y) => {
    return engToMin[y];
}));

for (let i = 0; i < word.length; i++)
    console.log(word[i]);