class Queue {
  constructor(items) {
    this.queue = items;
    this.top = 0;
  }

  push(value) {
    this.queue.push(value);
  }

  pop() {
    const popped = this.queue[this.top];
    this.top += 1;
    return popped;
  }

  isEmpty() {
    return this.queue.length - this.top === 0;
  }

  size() {
    return this.queue.length - this.top;
  }
}

const [N, K] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split(' ')
  .map(Number);

const queue = new Queue(
  Array.from({ length: N }).map((_, index) => index + 1)
);

while (queue.size() > 1) {
  const saved = queue.pop();

  for (let i = 1; i <= K - 1; i++) {
    if (queue.isEmpty()) {
      break;
    }

    queue.pop();
  }

  queue.push(saved);
}

const answer = queue.pop();
console.log(answer);
