const input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n');
let best = { no: 0, score: -1, submitted: 0, time: 0 };

for (let i = 1; i < input.length; i++) {
    input[i] = input[i].split(' ').map(x => parseInt(x));
    const cur = {
        no: i,
        score: input[i][0],
        submitted: input[i][1],
        time: input[i][2]
    };

    if (cur.score !== best.score) {
        if (cur.score > best.score)
            best = JSON.parse(JSON.stringify(cur));
        continue;
    }

    if (cur.submitted !== best.submitted) {
        if (cur.submitted < best.submitted)
            best = JSON.parse(JSON.stringify(cur));
        continue;
    }

    if (cur.time < best.time)
        best = JSON.parse(JSON.stringify(cur));
}

console.log(best.no);