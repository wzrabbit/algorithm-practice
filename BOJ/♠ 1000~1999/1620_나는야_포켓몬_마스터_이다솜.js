const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
const [pokemon, question] = input[0].split(' ').map(Number);
let result = '';

let pokemonFinder = new Map();
let numFinder = new Map();
for (let i = 1; i <= pokemon; i++) {
  pokemonFinder.set(i, input[i]);
  numFinder.set(input[i], i);
}

for (let i = pokemon + 1; i <= pokemon + question; i++) {

  if (isNaN(input[i])) result += numFinder.get(input[i]) + '\n';
  else result += pokemonFinder.get(parseInt(input[i])) + '\n';
}

result = result.slice(0, -1);
console.log(result);