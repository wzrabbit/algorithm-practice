console.log(
  require("fs")
    .readFileSync(0, "utf-8")
    .trim()
    .split("\n")[1]
    .replace(/[aeiouy](?=[^aeiouy ]{2,})/g, "")
    .split("")
    .reverse()
    .join("")
);
