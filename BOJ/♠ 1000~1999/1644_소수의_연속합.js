const num = parseInt(require('fs').readFileSync('/dev/stdin'));
let sieve = new Array(num + 1).fill(true);
let board = [];

for (let i = 2; i <= Math.sqrt(num); i++) {
    if (sieve[i] === true) {
        for (let j = i * 2; j <= num; j += i) {
            sieve[j] = false;
        }
    }
}

for (let i = 2; i <= num; i++) {
    if (sieve[i] === true) {
        board.push(i);
    }
}
board.push(-1);

let left = 0;
let right = 0;
let sum_ = 2;
let count = 0;
while (right < board.length - 1) {
    if (sum_ > num) {
        sum_ -= board[left];
        left++;
    }
    else if (sum_ < num) {
        right++;
        sum_ += board[right];
    }
    else {
        count++;
        right++;
        sum_ += board[right];
    }
}

console.log(count);