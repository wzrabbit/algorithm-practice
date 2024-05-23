const convertToAncientEnglish = (word) => {
    const isCapital = word
      .split("")
      .map((letter) => letter === letter.toUpperCase());
  
    word = word.replace(/^s|s(?=h)/gi, "!");
    word = word.replaceAll("s", "th");
    word = word.replaceAll("!", "s");
  
    word = word.replace(/^e/gi, "ae");
  
    word = word.replace(/o{2,}/gi, (matched) => {
      return `ou${matched.slice(2)}`;
    });
  
    word = word
      .split("")
      .map((letter, index) => {
        return isCapital[index] ? letter.toUpperCase() : letter.toLowerCase();
      })
      .join("");
  
    return word;
  };
  
  const [_, ...input] = require("fs").readFileSync(0, "utf-8").trim().split("\n");
  let output = "";
  input.forEach((word) => {
    output += `${convertToAncientEnglish(word)}\n`;
  });
  
  console.log(output);
  