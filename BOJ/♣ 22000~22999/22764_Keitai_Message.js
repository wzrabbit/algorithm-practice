class KeyPad {
  #key = null;
  #index;
  #slotSize;
  #KEYPAD_DATA = Object.freeze({
    1: [".", ",", "!", "?", " "],
    2: ["a", "b", "c"],
    3: ["d", "e", "f"],
    4: ["g", "h", "i"],
    5: ["j", "k", "l"],
    6: ["m", "n", "o"],
    7: ["p", "q", "r", "s"],
    8: ["t", "u", "v"],
    9: ["w", "x", "y", "z"],
  });

  pressKey(key) {
    if (this.#key === null) {
      this.#key = key;
      this.#index = 0;
      this.#slotSize = this.#KEYPAD_DATA[this.#key].length;
      return;
    }

    this.#index = (this.#index + 1) % this.#slotSize;
  }

  getKey() {
    if (this.#key === null) {
      return "";
    }

    const receivedKey = this.#KEYPAD_DATA[this.#key][this.#index];
    this.#resetKey();
    return receivedKey;
  }

  #resetKey() {
    this.#key = null;
  }
}

const solve = (command) => {
  const keyPad = new KeyPad();
  command.split("").forEach((letter) => {
    if (letter === "0") {
      printer += keyPad.getKey();
    } else {
      keyPad.pressKey(letter);
    }
  });
  printer += "\n";
};

const [_, ...input] = require("fs")
  .readFileSync(0, "utf-8")
  .toString()
  .trim()
  .split("\n");

let printer = "";

input.forEach((command) => {
  solve(command);
});

console.log(printer);
