const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n')
const [n, m] = input[0].split(' ').map(Number);
const numbers = input[1].split(' ').map(Number);
numbers.sort((a, b) => a - b);
let visited = [];
let result = '';

numbers.forEach((num) => {
  dfs(num);
});

function dfs(current) {
    visited.push(current);

    // 원하는 길이의 조합을 얻은 경우에는 결과에 값 추가 후 탐색 종료
    if (visited.length === m) {
      result += visited.join(' ') + '\n';
      visited.pop();
      return;
    }

    // 다음 수를 탐색하기 위한 재귀 호출
    numbers.forEach((num) => {
      if (!visited.includes(num)) {
        dfs(num);
      }
    });

    // 탐색을 마친 후에는 방문한 원소에서 자신의 원소 제외
    visited.pop();
}

console.log(result);
