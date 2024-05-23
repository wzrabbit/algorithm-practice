const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n')[1];
const matched = input.match(/A\+|A0|A-|B\+|B0|B-|C\+|C0|C-|A|B|C/g);
let output = '';

const getTransformedGrade = (grade, index) => {
  if (['C+', 'C0', 'C', 'C-'].includes(grade)) {
    return 'B';
  }
  
  if (['B0', 'B', 'B-'].includes(grade)) {
    if (index === 0 || ['C+', 'C0', 'C', 'C-'].includes(matched[index - 1])) {
      return 'D';
    }

    return 'B';
  }
  
  if (['A-', 'B+'].includes(grade)) {
    if (index === 0 || ['B0', 'B', 'B-', 'C+', 'C0', 'C', 'C-'].includes(matched[index - 1])) {
      return 'P';
    }
    
    return 'D';
  }
  
  if (['A0', 'A'].includes(grade)) {
    if (index === 0 || ['A-', 'B+', 'B0', 'B', 'B-', 'C+', 'C0', 'C', 'C-'].includes(matched[index - 1])) {
      return 'E';
    }
    
    return 'P';
  }
  
  return 'E';
}

matched.forEach((grade, index) => {
  output += `${getTransformedGrade(grade, index)}`;
});

console.log(output);
