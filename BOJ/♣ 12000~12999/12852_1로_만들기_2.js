const input = parseInt(require('fs').readFileSync('/dev/stdin'));
let dp = [null, 0, 1, 1]; // 연산을 하는 최소 횟수
let history = [null, 'end', 1, 3]; // 연산 직전의 행동
let result = '';

for (let i = 4; i <= input; i++) {
    let min = [999999, 0];
    // 3으로 나누는 선택지
    if (i % 3 === 0) {
        if (dp[i / 3] + 1 < min[0]) min = [dp[i / 3] + 1, 3];
    }
    // 2로 나누는 선택지
    if (i % 2 === 0) {
        if (dp[i / 2] + 1 < min[0]) min = [dp[i / 2] + 1, 2];
    }
    // 1을 빼는 선택지
    if (dp[i - 1] < min[0]) min = [dp[i - 1] + 1, 1];

    dp.push(min[0]);
    history.push(min[1]);
}

// 결과 출력
result += dp[input] + '\n';
let search = input;
while (history[search] !== 'end') {
    result += search + ' ';
    if (history[search] === 3) search /= 3;
    else if (history[search] === 2) search /= 2;
    else search -= 1;
}
result += '1';

console.log(result);