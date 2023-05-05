class ElementCounter {
  elementCount = Array(100001).fill(0);
  occurCount = Array(100001).fill(0);
  bestCount = 0;

  constructor() {
    this.occurCount[0] = 100000;
  }

  add = (num) => {
    const count = this.elementCount[num];

    this.elementCount[num] += 1;
    this.occurCount[count] -= 1;
    this.occurCount[count + 1] += 1;

    if (this.occurCount[count + 1] === 1 && count === this.bestCount) {
      this.bestCount = count + 1;
    }
  }

  remove = (num) => {
    const count = this.elementCount[num];

    this.elementCount[num] -= 1;
    this.occurCount[count] -= 1;
    this.occurCount[count - 1] += 1;

    if (this.occurCount[count] === 0 && count === this.bestCount) {
      this.bestCount = count - 1;
    }
  }

  getBestCount = () => {
    return this.bestCount;
  }
}

const moveToNext = (beforeStart, beforeEnd, afterStart, afterEnd) => {
  while (beforeStart > afterStart) elementCounter.add(arr[--beforeStart]);
  while (beforeStart < afterStart) elementCounter.remove(arr[beforeStart++]);
  while (beforeEnd > afterEnd) elementCounter.remove(arr[beforeEnd--]);
  while (beforeEnd < afterEnd) elementCounter.add(arr[++beforeEnd]);
}

const SQRT = 500;

let [N, arr, Q, ...queries] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

[N, Q] = [Number(N), Number(Q)];



arr = arr.split(' ').map(Number);
queries = queries.map((query, index) => {
  const [start, end] = query.split(' ').map(Number);
  return { queryNo: index, start: start - 1, end: end - 1 };
});

queries.sort((a, b) => {
  if (Math.floor(a.start / SQRT) !== Math.floor(b.start / SQRT)) return a.start - b.start;
  return a.end - b.end;
});

const answers = new Array(Q);
const elementCounter = new ElementCounter();

let [start, end] = [queries[0].start, queries[0].end];

for (let i = start; i <= end; i++) {
  elementCounter.add(arr[i]);
}

answers[queries[0].queryNo] = elementCounter.getBestCount();

for (let i = 1; i < Q; i++) {
  moveToNext(start, end, queries[i].start, queries[i].end);

  [start, end] = [queries[i].start, queries[i].end];
  answers[queries[i].queryNo] = elementCounter.getBestCount();
}

console.log(answers.join('\n'));

