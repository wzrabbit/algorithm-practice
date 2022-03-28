class Heap {
    constructor() {
        this.heap = [];
    }
    swap(a, b) {
        [this.heap[a], this.heap[b]] = [this.heap[b], this.heap[a]];
    }
    push(item) {
        this.heap.push(item);
        let c = this.heap.length - 1;
        let p = Math.floor((c - 1) / 2);
        while (p >= 0) {
            if (this.heap[c] < this.heap[p]) {
                this.swap(c, p);
                c = p;
                p = Math.floor((c - 1) / 2);
            }
            else break;
        }
    }
    pop() {
        if (this.heap.length === 0) return 'empty';
        else if (this.heap.length === 1) return this.heap.pop();
        this.swap(0, this.heap.length - 1);
        const popped = this.heap.pop();
        let c = 0;
        let p = 1;
        while (p < this.heap.length) {
            if (this.heap[c] > this.heap[p] || (this.heap[p + 1] !== undefined && this.heap[c] > this.heap[p + 1])) {
                if (this.heap[p + 1] === undefined || this.heap[p] < this.heap[p + 1]) {
                    this.swap(c, p);
                    c = p;
                    p = p * 2 + 1;
                }
                else {
                    this.swap(c, p + 1);
                    c = p + 1;
                    p = (p + 1) * 2 + 1;
                }
            }
            else break;
        }
        return popped;
    }
}

const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const cases = parseInt(input[0]);
let result = '';

for (let i = 1; i <= cases; i++) {
    let slimes = input[i * 2].split(' ').map((x) => BigInt(x));
    let energy = 1n;
    let bag = new Heap();
    for (let j = 0; j < slimes.length; j++) {
        bag.push(slimes[j]);
    }
    while (bag.heap.length > 1) {
        let mergedSlime = bag.pop() * bag.pop();
        bag.push(mergedSlime);
        energy *= mergedSlime;
    }
    result += (energy % 1000000007n).toString() + '\n';
}

console.log(result);