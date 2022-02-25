const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let [hear, see] = input[0].split(' ').map(Number);

let hearSet = new Set();
for (let i = 1; i <= hear; i++) {
    hearSet.add(input[i]);
}

let seeSet = new Set();
for (let i = hear + 1; i <= hear + see; i++) {
    seeSet.add(input[i]);
}

let finalSet = new Set();
let bigger = hearSet.length > seeSet.length ? 'h' : 's';
if (bigger === 'h') {
    hearSet.forEach((name) => {
        if (seeSet.has(name)) finalSet.add(name);
    });
}
else {
    seeSet.forEach((name) => {
        if (hearSet.has(name)) finalSet.add(name);
    });
}

finalSet = [...finalSet].sort();
console.log(finalSet.length + '\n' + finalSet.join('\n'));
