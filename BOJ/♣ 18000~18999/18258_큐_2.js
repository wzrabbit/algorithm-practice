const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let queue = [];
let [left, right] = [0, -1];
let printer = '';

for (let i = 1; i < input.length; i++) {
    const command = input[i];

    if (command.startsWith('push')) {
        const data = parseInt(command.replace('push ', ''));
        queue.push(data);
        right++;
    }
    else if (command === 'pop') {
        if (left > right)
            printer += '-1\n';
        else {
            printer += queue[left] + '\n';
            left++;
        }
    }
    else if (command === 'size')
        printer += right - left + 1 + '\n';
    else if (command === 'empty')
        printer += (left > right) ? '1\n' : '0\n';
    else if (command === 'front') {
        if (left > right)
            printer += '-1\n';
        else
            printer += queue[left] + '\n';
    }
    else {
        if (left > right)
            printer += '-1\n';
        else
            printer += queue[right] + '\n';
    }
}

console.log(printer);