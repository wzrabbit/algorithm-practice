const [a, b] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let result = '';
// &
for (let i = 0; i < a.length; i++) {
    result += (a[i] === '1' && b[i] === '1') ? '1' : '0';
}
result += '\n';
// |
for (let i = 0; i < a.length; i++) {
    result += (a[i] === '1' || b[i] === '1') ? '1' : '0';
}
result += '\n';
// ^
for (let i = 0; i < a.length; i++) {
    result += (a[i] !== b[i]) ? '1' : '0';
}
result += '\n';
// ~A
for (let i = 0; i < a.length; i++) {
    result += (a[i] === '1') ? '0' : '1';
}
result += '\n';
// ~B
for (let i = 0; i < a.length; i++) {
    result += (b[i] === '1') ? '0' : '1';
}
result += '\n';

console.log(result);