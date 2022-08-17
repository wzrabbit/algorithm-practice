const N = parseInt(require('fs').readFileSync('/dev/stdin'));
let printer = '';

for (let i = 0; i < N * 5; i++) {
    if (Math.floor(i / N) % 2)
        printer += '@'.repeat(N) + '\n';
    else
        printer += '@'.repeat(N * 5) + '\n';
}

console.log(printer);