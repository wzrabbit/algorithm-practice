const N = parseInt(require('fs').readFileSync('/dev/stdin'));
let printer = '';

printer += ('@'.repeat(N) + ' '.repeat(N * 3) + '@'.repeat(N) + '\n').repeat(N);
printer += ('@'.repeat(N) + ' '.repeat(N * 2) + '@'.repeat(N) + '\n').repeat(N);
printer += ('@'.repeat(N * 3) + '\n').repeat(N);
printer += ('@'.repeat(N) + ' '.repeat(N * 2) + '@'.repeat(N) + '\n').repeat(N);
printer += ('@'.repeat(N) + ' '.repeat(N * 3) + '@'.repeat(N) + '\n').repeat(N);

console.log(printer);