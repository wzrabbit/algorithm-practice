const N = parseInt(require('fs').readFileSync(0, 'utf-8'));
printer = '';

for (let i = N; i > 1; i--) {
    printer += `${i} bottles of beer on the wall, ${i} bottles of beer.\n`;
    printer += `Take one down and pass it around, ${i - 1} ${(i - 1) === 1 ? 'bottle' : 'bottles'} of beer on the wall.\n\n`;
}

printer += `1 bottle of beer on the wall, 1 bottle of beer.\n`;
printer += `Take one down and pass it around, no more bottles of beer on the wall.\n\n`;
printer += `No more bottles of beer on the wall, no more bottles of beer.\n`;
printer += `Go to the store and buy some more, ${N} ${N === 1 ? 'bottle' : 'bottles'} of beer on the wall.`;

console.log(printer);