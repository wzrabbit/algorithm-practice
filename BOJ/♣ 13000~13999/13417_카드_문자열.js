let input = require("fs").readFileSync("/dev/stdin").toString().trim().split('\n');
let result = '';

for (let i = 2; i < input.length; i += 2) {
    const cards = input[i].split(' ');
    let table = [cards[0]];

    for (let j = 1; j < cards.length; j++) {
        if (cards[j] > table[0]) table.push(cards[j]);
        else table.unshift(cards[j]);
    }

    result += table.join('') + '\n';
}

console.log(result);