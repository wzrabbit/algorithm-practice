const N = parseInt(require('fs').readFileSync(0, 'utf-8'));
let printer = '';

printer += `${(N ** 2 - N) / 2}\n`;
for (let i = 0; i < N; i++)
    printer += `${2 ** i} `;
printer += '\n';

printer += `${N - 1}\n`;
for (let i = 1; i <= N; i++)
    printer += `${i} `;

console.log(printer);