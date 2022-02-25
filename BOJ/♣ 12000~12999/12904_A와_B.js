let [start, end] = require("fs").readFileSync("/dev/stdin").toString().trim().split('\n');
start = start.split('');
end = end.split('');

while (start.length !== end.length) {
    if (end.pop() === 'B') end = end.reverse();
}

if (start.join('') === end.join('')) console.log(1);
else console.log(0);