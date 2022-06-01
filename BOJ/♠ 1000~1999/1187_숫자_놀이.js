let input = require('fs').readFileSync('/dev/stdin').toString().
    trim().split('\n')[1].split(' ').map((x) => parseInt(x));
let goal = Math.ceil(input.length / 2);
let current = 2;
let before = [];
let after = [];

for (let i = 0; i < input.length; i++)
    before.push({ items: [input[i]], sum: input[i], mod: input[i] % 2 });
before.sort((x, y) => x.mod - y.mod);

while (goal >= current) {

    let i = 0;
    while (i < before.length - 1) {
        let mergeMod = before[i].mod + before[i + 1].mod;
        let mergeSum = before[i].sum + before[i + 1].sum;
        if (mergeMod % current === 0) {
            after.push({
                items: [].concat(before[i].items, before[i + 1].items),
                sum: mergeSum,
                mod: mergeSum % (current * 2)
            });
            i += 2;
        }
        else
            i++;
    }


    before = after.slice();
    before.sort((x, y) => x.mod - y.mod);
    after = [];
    current *= 2;
}

console.log(before[0].items.join(' '));