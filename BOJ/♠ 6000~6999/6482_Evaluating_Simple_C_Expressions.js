const input = require('fs').readFileSync(0, 'utf-8').split('\n');
input.pop();
let output = '';

const calculateEvaluationResult = (expression) => {
  const variableValues = {};
  let currentExpression = expression.replace(/ +/g, '');

  while (/(\+\+|--)[a-z]/.test(currentExpression)) {
    currentExpression = currentExpression.replace(/(\+\+|--)[a-z]/, (matched) => {
      const letter = matched[2];
      const letterValue = letter.charCodeAt() - 96;
      const resultValue = matched.startsWith('++') ? letterValue + 1 : letterValue - 1;

      variableValues[letter] = resultValue;
      return resultValue;
    });
  }

  while (/[a-z](\+\+|--)/.test(currentExpression)) {
    currentExpression = currentExpression.replace(/[a-z](\+\+|--)/, (matched) => {
      const letter = matched[0];
      const letterValue = letter.charCodeAt() - 96;
      const resultValue = matched.endsWith('++') ? letterValue + 1 : letterValue - 1;

      variableValues[letter] = resultValue;
      return letterValue;
    });
  }

  currentExpression = currentExpression.replace(/[a-z]/g, (letter) => {
    const letterValue = letter.charCodeAt() - 96;
    variableValues[letter] = letterValue;
    return letterValue;
  });

  const result = eval(currentExpression);

  writeAnswer(expression, result, variableValues);
};

const writeAnswer = (expression, result, variableValues) => {
  const variableValuesArray = [...Object.entries(variableValues)].sort((a, b) => a[0] > b[0] ? 1 : -1);
  
  output += `Expression: ${expression}\n`;
  output += `    value = ${result}\n`;

  variableValuesArray.forEach(([letter, value]) => {
    output += `    ${letter} = ${value}\n`;
  });
};

input.forEach((expression) => {
  calculateEvaluationResult(expression);
});

console.log(output);
