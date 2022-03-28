const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [row, col] = input[0].split(' ').map((x) => parseInt(x));
const board = input.slice(1, row + 1).map((x) => x.slice().split(''));
const command = input[row + 1];
let location = [0, 0];
let monsterList = {};
let itemList = {};
let monster;
let turn = 0;

let found = false;
for (let r = 0; r < row; r++) {
    for (let c = 0; c < col; c++) {
        if (board[r][c] === '@') {
            board[r][c] = '.';
            location = [r, c];
            found = true;
            break;
        }
    }
    if (found) break;
}

class Player {
    constructor([startRow, startCol]) {
        this.lv = 1;
        this.maxhp = 20;
        this.hp = 20;
        this.atk = 2;
        this.def = 2;
        this.needexp = 5;
        this.exp = 0;
        this.weapon = 0;
        this.armor = 0;
        this.accessory = {
            'HR': false, 'RE': false, 'CO': false, 'EX': false,
            'DX': false, 'HU': false, 'CU': false
        };
        this.accessoryCount = 0;
        this.row = startRow;
        this.col = startCol;
    }
    healIfBoss() {
        if (monster.boss && this.accessory['HU']) {
            this.hp = this.maxhp;
        }
    }
    attack(isFirst) {
        let damage = this.atk + this.weapon;
        let mul = 1;
        if (isFirst) {
            if (this.accessory['CO']) mul += 1;
            if (this.accessory['CO'] && this.accessory['DX']) mul += 1;
            damage *= mul;
        }
        monster.hp -= Math.max(1, damage - monster.def);
        if (monster.isAlive() === false) this.earnEXP();
    }
    getTile() {
        return board[this.row][this.col];
    }
    getLocation() {
        return [this.row, this.col];
    }
    isAlive() {
        if (this.hp > 0) return true;
        else return false;
    }
    move(direction) {
        switch (direction) {
            case 'U':
                if (this.row > 0 && board[this.row - 1][this.col] !== '#') this.row -= 1; break;
            case 'D':
                if (this.row < row - 1 && board[this.row + 1][this.col] !== '#') this.row += 1; break;
            case 'L':
                if (this.col > 0 && board[this.row][this.col - 1] !== '#') this.col -= 1; break;
            case 'R':
                if (this.col < col - 1 && board[this.row][this.col + 1] !== '#') this.col += 1; break;
        }
    }
    getSpikeDamage() {
        this.hp = Math.max(0, (this.accessory['DX']) ? this.hp - 1 : this.hp - 5);
    }
    equipItem() {
        let item = itemList[`${this.row} ${this.col}`];
        switch (item.type) {
            case 'W':
                this.weapon = item.data; break;
            case 'A':
                this.armor = item.data; break;
            case 'O':
                if (this.accessory[item.data] === false && this.accessoryCount < 4) {
                    this.accessory[item.data] = true;
                    this.accessoryCount++;
                }
                break;
        }
    }
    earnEXP() {
        this.exp += Math.floor(monster.exp * ((this.accessory['EX']) ? 1.2 : 1));
        if (this.accessory['HR']) this.hp = Math.min(this.maxhp, this.hp + 3);
        if (this.exp >= this.needexp) {
            this.exp = 0;
            this.lv += 1;
            this.maxhp += 5;
            this.hp = this.maxhp;
            this.needexp += 5;
            this.atk += 2;
            this.def += 2;
        }
    }
    clearLand() {
        board[this.row][this.col] = '.';
    }
    markLand() {
        board[this.row][this.col] = '@';
    }
    tryToResurrect() {
        if (this.accessory['RE']) {
            this.accessory['RE'] = false;
            this.accessoryCount -= 1;
            this.row = location[0];
            this.col = location[1];
            this.hp = this.maxhp;
        }
    }
}

class Monster {
    constructor(data, isBoss) {
        this.name = data.name;
        this.hp = data.hp;
        this.atk = data.atk;
        this.def = data.def;
        this.exp = data.exp;
        this.boss = isBoss;
    }
    attack(isFirst) {
        if (isFirst && this.boss && player.accessory['HU']) return;
        player.hp -= Math.max(1, this.atk - player.def - player.armor);
        if (player.hp < 0) player.hp = 0;
    }
    isAlive() {
        if (this.hp > 0) return true;
        else return false;
    }
}

for (let i = row + 2; i < input.length; i++) {
    const data = input[i].split(' ');
    if (data.length === 7) {
        monsterList[`${parseInt(data[0]) - 1} ${parseInt(data[1]) - 1}`] = {
            'name': data[2],
            'atk': parseInt(data[3]),
            'def': parseInt(data[4]),
            'hp': parseInt(data[5]),
            'exp': parseInt(data[6])
        }
    }
    else {
        itemList[`${parseInt(data[0]) - 1} ${parseInt(data[1]) - 1}`] = {
            'type': data[2],
            'data': isNaN(parseInt(data[3])) ? data[3] : parseInt(data[3])
        }
    }
}

function game() {
    for (let i = 0; i < command.length; i++) {
        turn++;
        player.move(command[i]);
        switch (player.getTile()) {
            case '&':
                fight(player.getLocation(), false); break;
            case 'M':
                fight(player.getLocation(), true); break;
            case '^':
                player.getSpikeDamage(); break;
            case 'B':
                player.equipItem(); break;
        }
        if (player.isAlive()) {
            if (player.getTile() === 'M') {
                printResult('Victory');
                return;
            }
            if (player.getTile() !== '^') player.clearLand();
        }
        else {
            player.tryToResurrect();
            if (player.isAlive() === false) {
                printResult('Defeat');
                return;
            }
        }
    }
    printResult('Continue');
}

function fight([monsterRow, monsterCol], isBoss) {
    monster = new Monster(monsterList[`${monsterRow} ${monsterCol}`], isBoss);
    let isFirst = true;
    player.healIfBoss();
    while (true) {
        if (player.isAlive()) {
            player.attack(isFirst);
        }
        else return;
        if (monster.isAlive()) {
            monster.attack(isFirst);
        }
        else return;
        if (isFirst) isFirst = false;
    }
}

function printResult(result) {
    let printer = '';
    if (result !== 'Defeat') player.markLand();
    for (let i = 0; i < row; i++) {
        printer += board[i].join('') + '\n';
    }
    printer += `Passed Turns : ${turn}
LV : ${player.lv}
HP : ${player.hp}/${player.maxhp}
ATT : ${player.atk}+${player.weapon}
DEF : ${player.def}+${player.armor}
EXP : ${player.exp}/${player.needexp}
`;
    switch (result) {
        case 'Victory':
            printer += 'YOU WIN!'; break;
        case 'Defeat':
            let killer;
            if (player.getTile() === '^') killer = 'SPIKE TRAP';
            else killer = monster.name;
            printer += `YOU HAVE BEEN KILLED BY ${killer}..`;
            break;
        case 'Continue':
            printer += 'Press any key to continue.';
    }
    console.log(printer);
}

let player = new Player(location);
game();