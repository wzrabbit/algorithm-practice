const answer = new Array(10001).fill(true);

for (let i = 1; i <= 10000; i++) {
    const splited = i.toString().split('').map((x) => parseInt(x));
    let produced = i;
    for (let j = 0; j < splited.length; j++) {
        produced += splited[j];
    }
    answer[produced] = false;
}

let result = '';
for (let i = 1; i <= 10000; i++) {
    if (answer[i] === true) {
        result += i + '\n';
    }
}

console.log(result);