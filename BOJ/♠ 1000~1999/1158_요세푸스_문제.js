const [num, skip] = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map((x) => parseInt(x));
let board = [];
let printer = '<';
let pointer = 0;

for (let i = 0; i <= num - 1; i++)
    board.push({ 'current': i, 'next': i + 1 });
board.push({ 'current': num, 'next': 1 });

for (let i = 1; i <= num; i++) {
    for (let j = 1; j <= skip - 1; j++)
        pointer = board[pointer].next;

    let previous = pointer;
    pointer = board[previous].next;
    let next = board[pointer].next;

    printer += pointer + ', ';
    board[previous].next = next;
}

printer = printer.slice(0, -2) + '>';
console.log(printer);