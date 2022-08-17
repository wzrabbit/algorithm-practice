let N = parseInt(require('fs').readFileSync(0, 'utf-8'));
N--;
let text = 'Messi Gimossi ';
let len = [0, 6, 14];

while (len.length <= 40)
    len.push(len[len.length - 1] + len[len.length - 2]);

for (let i = 40; i >= 2; i--) {
    if (N >= len[i])
        N -= len[i];
}

if (text[N] === ' ')
    console.log('Messi Messi Gimossi');
else
    console.log(text[N]);