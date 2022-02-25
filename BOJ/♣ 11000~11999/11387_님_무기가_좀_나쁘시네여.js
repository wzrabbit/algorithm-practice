const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const kri = input[0].split(" ").map(Number);
const pavu = input[1].split(" ").map(Number);
const kriWeapon = input[2].split(" ").map(Number);
const pavuWeapon = input[3].split(" ").map(Number);

const kriPower = calcPower(kri);
const pavuPower = calcPower(pavu);

const kriNewPower = calcPower(
  [
    kri[0] - kriWeapon[0] + pavuWeapon[0],
    kri[1] - kriWeapon[1] + pavuWeapon[1],
    kri[2] - kriWeapon[2] + pavuWeapon[2],
    kri[3] - kriWeapon[3] + pavuWeapon[3],
    kri[4] - kriWeapon[4] + pavuWeapon[4]
]);

const pavuNewPower = calcPower(
  [
    pavu[0] - pavuWeapon[0] + kriWeapon[0],
    pavu[1] - pavuWeapon[1] + kriWeapon[1],
    pavu[2] - pavuWeapon[2] + kriWeapon[2],
    pavu[3] - pavuWeapon[3] + kriWeapon[3],
    pavu[4] - pavuWeapon[4] + kriWeapon[4]
]);

if (kriNewPower - kriPower > 0) console.log("+");
else if (kriNewPower - kriPower < 0) console.log("-");
else console.log("0");

if (pavuNewPower - pavuPower > 0) console.log("+");
else if (pavuNewPower - pavuPower < 0) console.log("-");
else console.log("0");

function calcPower([attack, strength, critChance, critPower, attackSpeed]) {
  critChance = critChance > 100 ? 100 : critChance;
  
  let power = attack * ( 1 + strength / 100 ) * ((10000 - critChance * 100) + critChance * critPower) * (100 + attackSpeed);
  return power / 1000000;
  // 공식을 그대로 사용할 경우 실수와의 연산을 허용하게 되고, 그로 인해 부동소수점 발생이 되어 잘못된 연산 기록을 초래하므로
  // 공식의 일부에 임의의 숫자를 곱해 실수와의 연산을 피하고, 대신 결과에 곱한 만큼의 숫자를 나눠 준다
}