const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const [N, _, K] = input[0].split(' ').map(Number);
const greetingPeople = input.slice(1).map(Number);
const shouldGreet = Array.from({ length: N }).map(() => false);

greetingPeople.forEach((person) => {
  shouldGreet[person] = true;
});

const greet = () => {
  const prevShouldGreet = [shouldGreet.at(-1), ...shouldGreet, shouldGreet[0]];

  for (let i = 1; i <= N; i++) {
    if (
      (prevShouldGreet[i - 1] && !prevShouldGreet[i + 1]) ||
      (!prevShouldGreet[i - 1] && prevShouldGreet[i + 1])
    ) {
      shouldGreet[i - 1] = true;
      continue;
    }

    shouldGreet[i - 1] = false;
  }
};

for (let i = 0; i < K; i++) {
  greet();
}

const greetingPeopleCount = shouldGreet.reduce((acc, cur) => acc + (cur ? 1 : 0), 0);

console.log(greetingPeopleCount);
