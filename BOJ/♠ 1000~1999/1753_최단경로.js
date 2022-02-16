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
        if (this.heap[c][1] < this.heap[p][1]) {
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
        if (this.heap[c][1] > this.heap[p][1] || (this.heap[p + 1] !== undefined && this.heap[c][1] > this.heap[p + 1][1])) {
          if (this.heap[p + 1] === undefined || this.heap[p][1] < this.heap[p + 1][1]) {
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
  
  function dijkstra(start) {
    let queue = new Heap();
    queue.push([start, 0]);
    dist[start] = 0;
    while (queue.heap.length > 0) {
      const [v, d] = queue.pop();
      if (d < dist[v]) continue;
      for (let i = 0; i < graph[v].length; i++) {
        nextV = graph[v][i][0];
        nextD = graph[v][i][1];
        let cost = d + nextD;
        if (cost < dist[nextV]) {
          dist[nextV] = cost;
          queue.push([nextV, cost]);
        }
      }
    }
  }
  
  const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
  const [vertex, edge] = input[0].split(' ').map((x) => parseInt(x));
  const start = parseInt(input[1]);
  const INF = 99999999;
  let dist = new Array(vertex + 1).fill(INF);
  let visited = new Array(vertex + 1).fill(false);
  let graph = new Array(vertex + 1);
  for (let i = 1; i <= vertex; i++) {
    graph[i] = [];
  }
  for (let i = 2; i < edge + 2; i++) {
    const [s, e, d] = input[i].split(' ').map((x) => parseInt(x));
    graph[s].push([e, d]);
  }
  dijkstra(start);
  
  result = '';
  for (let i = 1; i <= vertex; i++) {
    if (dist[i] === 99999999) dist[i] = 'INF';
    result += dist[i] + '\n';
  }
  
  console.log(result);