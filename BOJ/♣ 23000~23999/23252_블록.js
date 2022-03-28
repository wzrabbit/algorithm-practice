const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const cases = parseInt(input[0]);
let result = '';

for (let i = 1; i <= cases; i++) {
    let [a, b, c] = input[i].split(' ').map(Number);

    // 2칸짜리 블록만 홀수개 인 것은 유효하지 않음
    if (a === 0 && b % 2 === 1 && c === 0) {
        result += 'No\n';
        continue;
    }

    // 3칸짜리 블록이 있을 경우 반드시 그만큼의 1칸짜리 블록이 있어야 함
    if (a < c) {
        result += 'No\n';
        continue;
    }

    a = a % 2;
    b = b % 2;
    c = c % 2;

    // 블록의 총합이 짝수개여야 함
    if ((a + b * 2 + c * 3) % 2 === 0) result += 'Yes\n';
    else result += 'No\n';
}

console.log(result);