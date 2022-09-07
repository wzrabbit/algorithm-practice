const N = parseInt(require('fs').readFileSync(0, 'utf-8'));
let printer = 'YES\n';
let l = 1;
let r = 2 ** (N * 2);

for (let i = 0; i < 2 ** N; i++) {
    for (let j = 0; j < 2 ** N / 2; j++) {
        if (i % 2 === 0)
            printer += `${l++} ${r--} `;
        else
            printer += `${r--} ${l++} `;
    }
    printer += '\n';
}

if (N > 1)
    console.log(printer);
else
    console.log('NO');