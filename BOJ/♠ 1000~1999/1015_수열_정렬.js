const arr = require('fs').readFileSync('/dev/stdin').toString().
    trim().split('\n')[1].split(' ').map((x) => parseInt(x));
let id = 0;
let result = new Array(arr.length);

for (let i = 1; i <= 1000; i++) {
    for (let j = 0; j < arr.length; j++) {
        if (arr[j] === i)
            result[j] = id++;
    }
}

console.log(result.join(' '));