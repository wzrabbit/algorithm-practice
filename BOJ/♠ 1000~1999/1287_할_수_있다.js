let input = require('fs').readFileSync('/dev/stdin').toString().trim();
let error = false;

// 유효성 체크 - 연산자, 숫자 관련
if (/[+\-*/]{2,}|\([+\-*/]|[+\-*/]\)|^[+\-*/]|[+\-*/]$|\d+\(|\)\d+/.test(input)) error = true;
// 괄호에 아무것도 없는 경우도 ROCK 처리해야 함 (이건 우연히 발견했음)
if (/\(\d*\)/.test(input)) error = true;
// 유효성 체크 - 괄호 관련
let stack = [];
let brackets = input.match(/[()]/g) || [];
for (let i = 0; i < brackets.length; i++) {
  if (brackets[i] === '(') stack.push('(');
  else if (stack.length === 0) error = true;
  else (stack.pop());
}
if (stack.length !== 0) error = true;

if (error === false) {
  // 계산 (괄호 있을 때)
  while (input.includes('(')) {
    input = input.replace(/\([^()]*?\)/, (x) => {
      return calculator(x.slice(1, x.length - 1))
    });
  }

  // 계산 (괄호 없을 때)
  input = calculator(input);
  // 모든 계산은 끝났으므로 괄호 제거 후 결과 출력
  console.log(input.replace(/[[\]]/g, ''));

  // 사칙연산 계산기 (괄호 제외)
  function calculator(expression) {
    // 곱셈, 나눗셈 처리
    while (expression.includes('*') || expression.includes('/')) {
      expression = expression.replace(/\d+(\*|\/)\d+/, (x) => {
        if (x.includes('*')) return (BigInt(x.split('*')[0]) * BigInt(x.split('*')[1]));
        else return (BigInt(BigInt(x.split('/')[0]) / BigInt(x.split('/')[1]))).toString();
      });
    }
    // 음수가 있을 경우 []로 감싸서 임시 처리
    expression = expression.replace(/(?<=[+\-*\/])-\d+|^-\d+/g, (x) => {
      return '[' + x + ']';
    });
    // 덧셈, 뺄셈 처리. 역시 계산 중 음수가 발생하면 []로 감싸서 임시 처리
    while (expression.includes('+') || (expression.replace(/\[.*\]/g, '').includes('-'))) {
      expression = expression.replace(/(\[-)?\d+]?(\+|\-)(\[-)?\d+]?/, (x) => {
        if (x.includes('+')) {
          let calcResult = BigInt(x.split('+')[0].replace(/[[\]]/g, '')) + BigInt(x.split('+')[1].replace(/[[\]]/g, ''));
          return calcResult >= 0 ? calcResult.toString() : '[' + calcResult.toString() + ']';
        }
        else {
          x = x.replace(/(?<=\[)-/g, 'N');
          let calcResult = BigInt(x.split('-')[0].replace('N', '-').replace(/[[\]]/g, '')) - BigInt(x.split('-')[1].replace('N', '-').replace(/[[\]]/g, ''));
          return calcResult >= 0 ? calcResult.toString() : '[' + calcResult.toString() + ']';
        }
      });
    }
    return expression;
  }
}
if (error) console.log('ROCK');