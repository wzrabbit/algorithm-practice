// 그냥 제일 레벨 높은 카드 하나 잡아놓고 나머지 카드를 전부 흡수해버리면 되는 거 아닌가?
let cards = require("fs").readFileSync("/dev/stdin").toString().trim().split('\n')[1].split(' ').map(Number).sort((a, b) => a - b);
const maxCard = cards.pop();
let total = 0;
for (let i = 0; i < cards.length; i++) {
    total += cards[i];
}
total += maxCard * cards.length;

console.log(total);