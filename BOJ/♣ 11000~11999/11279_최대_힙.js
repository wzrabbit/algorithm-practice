const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map(Number);
let heap = [null];
let result = '';

for (let i = 1; i <= input[0]; i++) {
  if (input[i] === 0) deleteData();
  else addData(input[i]);
}

console.log(result);

// 힙 추가 연산
function addData(data) {
  heap.push(data);

  let comp = Math.floor((heap.length - 1) / 2);
  let prev = heap.length - 1;

  while (comp !== 0) {
    if (data > heap[comp]) {
      let temp = heap[comp];
      heap[comp] = data;
      heap[prev] = temp;
      prev = comp;
      comp = Math.floor(comp / 2);
    }
    else break;
  }
}

// 힙 삭제 연산
function deleteData(data) {
  if (heap.length === 1) {
    result += '0\n';
    return;
  }
  else if (heap.length === 2) {
    result += heap.pop() + '\n';
    return;
  }

  result += heap[1] + '\n';
  heap[1] = heap.pop();

  let comp = 2;
  let prev = 1;

  while (comp < heap.length) {
    let leftChild = heap[comp];
    let rightChild = heap[comp + 1] || 0;

    if (leftChild >= rightChild) {
      if (heap[prev] >= leftChild) break;
      let temp = heap[prev];
      heap[prev] = heap[comp];
      heap[comp] = temp;
      prev = comp;
      comp = comp * 2;
    }
    else {
      if (heap[prev] >= rightChild) break;
      let temp = heap[prev];
      heap[prev] = heap[comp + 1];
      heap[comp + 1] = temp;
      prev = comp + 1;
      comp = (comp + 1) * 2;
    }
  }
}