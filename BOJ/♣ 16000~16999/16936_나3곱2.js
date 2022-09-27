function getSquare(num, div) {
    let square = 0n;
    while (num % div === 0n) {
        num /= div;
        square++;
    }

    return square;
}

let [N, arr] = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n');
arr = arr.split(' ').map(x => BigInt(x));
let printer = '';

for (let i = 0; i < N; i++) {
    arr[i] = { num: arr[i], score: getSquare(arr[i], 2n) - getSquare(arr[i], 3n) };
}

arr.sort((a, b) => {
    if (a.score >= b.score)
        return 1;
    else
        return -1;
});

for (let i = 0; i < N; i++)
    printer += `${arr[i].num} `;

console.log(printer);