let input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
let tree = {
    0: { val: '', nextNode: [] }
};
let no = 1;

for (let i = 1; i < input.length; i++) {
    let data = input[i].split(' ');
    let current = 0;
    for (let j = 1; j < data.length; j++) {
        let edge = tree[current]['nextNode'];
        let success = false;
        for (let k = 0; k < edge.length; k++) {
            if (edge[k][0] === data[j]) {
                current = edge[k][1];
                success = true;
                break;
            }
        }
        if (success === false) {
            tree[current]['nextNode'].push([data[j], no]);
            tree[no] = { val: data[j], nextNode: [] }
            current = no;
            no++;
        }
    }
}

let result = '';
dfs(0, 0);
function dfs(current, level) {
    let edge = tree[current]['nextNode'].sort();
    for (let i = 0; i < edge.length; i++) {
        result += '--'.repeat(level) + edge[i][0] + '\n';
        dfs(edge[i][1], level + 1);
    }
}

console.log(result);