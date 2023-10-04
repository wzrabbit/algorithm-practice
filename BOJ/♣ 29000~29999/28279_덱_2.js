class Deque {
  deque = new Array(2_000_001);
  frontIndex = 1_000_000;
  backIndex = 1_000_001;

  pushFront(item) {
    this.deque[this.frontIndex] = item;
    this.frontIndex -= 1;
  }

  pushBack(item) {
    this.deque[this.backIndex] = item;
    this.backIndex += 1;
  }

  popFront() {
    if (this.getSize() === 0) {
      return -1;
    }

    this.frontIndex += 1;
    return this.deque[this.frontIndex];
  }

  popBack() {
    if (this.getSize() === 0) {
      return -1;
    }

    this.backIndex -= 1;
    return this.deque[this.backIndex];
  }

  getFront() {
    if (this.getSize() === 0) {
      return -1;
    }

    return this.deque[this.frontIndex + 1];
  }

  getBack() {
    if (this.getSize() === 0) {
      return -1;
    }

    return this.deque[this.backIndex - 1];
  }

  getSize() {
    return this.backIndex - this.frontIndex - 1;
  }

  isEmpty() {
    return this.getSize() === 0;
  }
}

let [N, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

N = Number(N);
let answer = '';
const deque = new Deque();

input.forEach((line) => {
  const command = line.split(' ').map(Number);

  switch (command[0]) {
    case 1:
      deque.pushFront(command[1]);
      break;
    case 2:
      deque.pushBack(command[1]);
      break;
    case 3:
      answer += `${deque.popFront()}\n`;
      break;
    case 4:
      answer += `${deque.popBack()}\n`;
      break;
    case 5:
      answer += `${deque.getSize()}\n`;
      break;
    case 6:
      answer += `${deque.isEmpty() ? 1 : 0}\n`;
      break;
    case 7:
      answer += `${deque.getFront()}\n`;
      break;
    case 8:
      answer += `${deque.getBack()}\n`;
      break;
  }
});

console.log(answer);
