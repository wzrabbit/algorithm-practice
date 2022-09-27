const N = parseInt(require('fs').readFileSync(0, 'utf-8'));
let printer = '';

if (N % 2 === 1) {
    printer += '*'.repeat(N) + '\n';
    let l = r = Math.floor(N / 2);

    while (l >= 0) {
        let raw = new Array(r).fill(' ');
        raw[l] = raw[r] = '*';
        printer += raw.join('') + '\n';
        l--; r++;
    }
}
else {
    printer = 'I LOVE CBNU';
}

console.log(printer);