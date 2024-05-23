const convertCppToJava = (variable) => {
  return variable.split('_').map((frag, index) => {
    if (index === 0) {
      return frag;
    }

    return frag[0].toUpperCase() + frag.slice(1);
  }).join('');
};

const convertJavaToCpp = (variable) => {
  return variable.match(/(^|[A-Z])[a-z]*/g).map((frag) =>
    frag.toLowerCase()
  ).join('_');
};

const input = require('fs').readFileSync(0, 'utf-8').trim();

const isCpp = /_/.test(input);
const isJava = /[A-Z]/.test(input);
const isInvalid = /__/.test(input) ||
  input[0] === '_' ||
  input.at(-1) === '_' ||
  /[A-Z]/.test(input[0]);

if ((isCpp && isJava) || isInvalid) {
  console.log('Error!');
  return;
}

if (isCpp) {
  console.log(convertCppToJava(input));
} else {
  console.log(convertJavaToCpp(input));
}
