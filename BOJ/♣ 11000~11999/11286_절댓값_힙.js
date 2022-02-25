class Heap {
    constructor() {
        this.heap = [];
    }
    swap(a, b) {
        [this.heap[a], this.heap[b]] = [this.heap[b], this.heap[a]];
    }
    compare(a, b) {
        if (this.heap[b] === undefined) return 'left';
        if (Math.abs(this.heap[a]) > Math.abs(this.heap[b])) {
            return 'right';
        }
        else if (Math.abs(this.heap[a]) < Math.abs(this.heap[b])) {
            return 'left';
        }
        else {
            if (this.heap[a] > this.heap[b]) {
                return 'right';
            }
            else return 'left';
        }
    }
    add(item) {
        this.heap.push(item);
        if (this.heap.length === 1) return;
        let c = this.heap.length - 1;
        let p = Math.floor((c - 1) / 2);
        while (p >= 0) {
            if (this.compare(c, p) === 'left') {
                this.swap(c, p);
                c = p;
                p = Math.floor((c - 1) / 2);
            }
            else break;
        }
    }
    remove() {
        if (this.heap.length === 0) return 0;
        this.swap(0, this.heap.length - 1);
        if (this.heap.length === 1) return this.heap.pop();
        const popped = this.heap.pop();
        let c = 0;
        let p = c * 2 + 1;
        while (this.heap[p] !== undefined) {
            if (this.compare(c, p) === 'right' || this.compare(c, p + 1) === 'right') {
                if (this.compare(p, p + 1) === 'right') {
                    this.swap(c, p + 1);
                    c = p + 1;
                    p = (p + 1) * 2 + 1;
                }
                else {
                    this.swap(c, p);
                    c = p;
                    p = p * 2 + 1;
                }
            }
            else break;
        }
        return popped;
    }
}

let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((x) => parseInt(x));
let h = new Heap();
let result = '';
for (let i = 1; i < input.length; i++) {
    if (input[i] !== 0) {
        h.add(input[i]);
    }
    else {
        result += h.remove() + '\n';
    }
}

console.log(result);