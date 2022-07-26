const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n')
    .map((x) => x.split(' ').map((y) => y.split('').map((z) => isNaN(z) ? z : parseInt(z))));
let printer = '';

for (let i = 0; i < input.length - 1; i++) {
    let pos = parseInt(input[i][0].join(''));
    let visited = new Array(20).fill(false);
    let legal = true;
    let notVisited = [];
    visited[pos] = true;

    for (let j = 1; j < input[i].length; j++) {
        if (input[i][j][0] === 'U')
            pos += input[i][j][1];
        else
            pos -= input[i][j][1];

        if (pos < 1 || pos > 20 || visited[pos] === true) {
            printer += 'illegal\n';
            legal = false;
            break;
        }

        visited[pos] = true;
    }

    if (legal) {
        for (let j = 1; j <= 20; j++) {
            if (!visited[j])
                notVisited.push(j);
        }

        if (notVisited.length === 0)
            printer += 'none\n';
        else
            printer += notVisited.join(' ') + '\n';
    }
}

console.log(printer);