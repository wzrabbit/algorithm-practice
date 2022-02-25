const input = parseInt(require('fs').readFileSync('/dev/stdin'));
let result = '';
let prime = [];

getPrimeNumbers(1003001);
for (let i = 0; i < prime.length; i++) {
    if (prime[i] >= input && isPalindrome(prime[i])) {
        console.log(prime[i]);
        break;
    }
}

function getPrimeNumbers(num) {
    let numbers = Array(num + 1).fill(true);
    numbers[1] = 0;

    for (let i = 2; i <= Math.sqrt(num); i++) {
        if (numbers[i] === false) continue;
        for (let j = i * 2; j <= num; j += i) {
            numbers[j] = false;
        }
    }

    for (let i = 2; i <= num; i++) {
        if (numbers[i] === true) prime.push(i);
    }
}

function isPalindrome(num) {
    let left, right;
    num = num.toString();

    if (num.length % 2) {
        left = right = Math.floor(num.length / 2);
    }
    else {
        left = num.length / 2 - 1;
        right = num.length / 2;
    }

    while (right < num.length) {
        if (num[left] !== num[right]) return false;
        left--; right++;
    }

    return true;
}