class Queue {
  constructor(startArray) {
    this.queue = startArray;
    this.index = 0;
  }

  push(item) {
    this.queue.push(item);
  }

  top() {
    return this.queue[this.index];
  }

  pop() {
    return this.queue[this.index++];
  }

  isEmpty() {
    return this.index === this.queue.length;
  }
}

const [_, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n')
  .map((sentence) => new Queue(sentence.split(' ')));

const sentenceQueue = input.pop();
const parrotQueues = input;

while (!sentenceQueue.isEmpty()) {
  const currentWord = sentenceQueue.top();
  const candidates = Array.from({ length: parrotQueues.length })
    .map((_, index) => parrotQueues[index].top());
  const foundIndex = candidates.findIndex(
    (_, index) => candidates[index] === currentWord
  );

  if (foundIndex === -1) {
    break;
  }

  sentenceQueue.pop();
  parrotQueues[foundIndex].pop();
}

const isPossible = [sentenceQueue, ...parrotQueues].every(
  (queue) => queue.isEmpty()
);

console.log(isPossible ? 'Possible' : 'Impossible');
