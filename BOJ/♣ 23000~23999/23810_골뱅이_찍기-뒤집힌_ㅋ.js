const N = parseInt(require('fs').readFileSync('/dev/stdin'));
let printer = '';

for (let i = 0; i < N * 5; i++) {
    if ([0, 2].includes(Math.floor(i / N)))
        printer += '@'.repeat(N * 5) + '\n';
    else
        printer += '@'.repeat(N) + '\n';
}

console.log(printer);