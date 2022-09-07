let input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n');
let data = [];

for (let i = 1; i < input.length; i++) {
    const [name, day, month, year] = input[i].split(' ');
    data.push({
        name: name,
        day: parseInt(day),
        month: parseInt(month),
        year: parseInt(year)
    });
}

data.sort((a, b) => {
    if (a.year !== b.year) {
        return a.year > b.year ? 1 : -1;
    }

    if (a.month !== b.month) {
        return a.month > b.month ? 1 : -1;
    }

    return a.day > b.day ? 1 : -1;
});

console.log(data[data.length - 1].name);
console.log(data[0].name);