class History {
  constructor() {
    this.queue = [];
    this.startPos = 0;
    this.consonantCount = 0;
  }

  add(sentence) {
    this.isLastChatGood = true;
    const sentenceData = { sentence: sentence, isConsonant: false };

    if (/[b-df-hj-np-tv-xz]{5}/i.test(sentence)) {
      this.consonantCount += 1;
      sentenceData.isConsonant = true;
    }

    this.queue.push(sentenceData);
    if (this.queue.length - this.startPos > 11) {
      this.remove();
    }
  }

  remove() {
    if (this.queue[this.startPos].isConsonant) {
      this.consonantCount -= 1;
    }
    this.startPos += 1;
  }

  lastChatCheckResult() {
    if (this.isConsonantExceeded()) return "n\n";
    if (this.hasSameSentence()) return "n\n";
    return "y\n";
  }

  isConsonantExceeded() {
    return (
      (this.consonantCount >= 4 &&
        this.queue[this.queue.length - 1].isConsonant) ||
      /[b-df-hj-np-tv-xz]{6}/i.test(this.queue[this.queue.length - 1].sentence)
    );
  }

  hasSameSentence() {
    const lastSentence = this.queue[this.queue.length - 1].sentence;
    let sameCount = 0;
    for (let index = this.startPos; index < this.queue.length - 1; index++) {
      if (this.queue[index].sentence === lastSentence) {
        sameCount += 1;
        if (sameCount > 1) return true;
      }
    }
    return false;
  }
}

const [, ...input] = require("fs")
  .readFileSync(0, "utf-8")
  .toString()
  .trim()
  .split("\n");

let history = new History();
let resultPrinter = "";

input.forEach((sentence) => {
  if (sentence.length >= 500) throw Error();
  history.add(sentence);
  resultPrinter += history.lastChatCheckResult();
});

console.log(resultPrinter);
