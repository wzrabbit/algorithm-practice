const N = parseInt(require('fs').readFileSync('/dev/stdin'));
let printer = '';

for (let i = 0; i < N * 5; i++) {
    if (i < N || i >= N * 4)
        printer += '@'.repeat(N * 5) + '\n';
    else
        printer += '@'.repeat(N) + ' '.repeat(N * 3) + '@'.repeat(N) + '\n';
}

console.log(printer);