const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
input.pop();
let result = '';

for (let i = 0; i < input.length; i++) {
    let stack = [];
    let need = 0;
    for (let j = 0; j < input[i].length; j++) {
        // '{' 면 push
        if (input[i][j] === '{') stack.push('{');
        // '}' 인데 '{' 가 없는 상태면 '{' 로 바꾸고 push, 변경 횟수 +1
        else if (stack.length === 0) {
            stack.push('{');
            need++;
        }
        // '}' 이고 '{' 가 있으면 평소대로 pop
        else stack.pop();
    }
    // 스택 연산 후 남은 '{' 의 개수 를 2로 나눈만큼 변경 횟수 증가
    // 남은 '{' 의 절반을 '}' 로 바꿔야 할테니까
    need += stack.length / 2;
    result += `${i + 1}. ${need}\n`;
}

console.log(result);
