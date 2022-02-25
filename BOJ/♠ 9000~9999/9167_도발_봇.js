let input = require('fs').readFileSync('/dev/stdin').toString();
input = input.replace(/\n.*$/, '');
input = input.split('\n');

let mod = {
    'taunt': 0, 'sentence': 0, 'modified-noun': 0, 'modifier': 0,
    'present-person': 0, 'past-person': 0, 'noun': 0, 'present-verb': 0,
    'past-verb': 0, 'adjective': 0, 'adverb': 0
}
let printer = '';
let task;

for (let i = 0; i < input.length; i++) {
    let current = input[i];
    let isHolyGrail = false;
    let wordCount = 0;
    let knightSentence;
    task = 0;

    current = knightSentence = current.replace(/ {2,}/g, ' ');
    if (/t.*h.*e.*h.*o.*l.*y.*g.*r.*a.*i.*l/i.test(current)) isHolyGrail = true;
    let spliter = current.split(' ');
    for (let j = 0; j < spliter.length; j++) {
        if (/[0-9A-z]/.test(spliter[j])) wordCount++;
    }
    task = Math.floor(wordCount / 3) + ((wordCount % 3 != 0) ? 1 : 0);

    printer += 'Knight: ' + current.replace(/^ +/, '') + '\n';
    while (task >= 1) {
        if (isHolyGrail) {
            printer += 'Taunter: (A childish hand gesture).\n';
            task--;
            isHolyGrail = false;
            continue;
        }
        printer += 'Taunter: ' + taunt() + '\n';
    }
    if (i !== input.length - 1) printer += '\n';
}

console.log(printer);

function taunt() {
    let result;
    switch (mod['taunt'] % 3) {
        case 0: case 2:
            result = caps(sentence()) + '.';
            task--;
            break;
        case 1:
            result = caps(noun()) + '! ' + caps(sentence()) + '.';
            task -= 2;
            break;
    }
    mod['taunt']++;
    return result;
}

function sentence() {
    let result;
    switch (mod['sentence'] % 3) {
        case 0:
            result = pastRel() + ' ' + nounPhrase(); break;
        case 1:
            result = presentRel() + ' ' + nounPhrase(); break;
        case 2:
            result = pastRel() + ' ' + article() + ' ' + noun(); break;
    }
    mod['sentence']++;
    return result;
}

function nounPhrase() {
    return article() + ' ' + modifiedNoun();
}

function modifiedNoun() {
    let result;
    if (mod['modified-noun'] % 2 === 0) {
        result = noun();
    }
    else {
        result = modifier() + ' ' + noun();
    }
    mod['modified-noun']++;
    return result;
}

function modifier() {
    let result;
    if (mod['modifier'] % 2 === 0) {
        result = adjective();
    }
    else {
        result = adverb() + ' ' + adjective();
    }
    mod['modifier']++;
    return result;
}

function presentRel() {
    return 'your ' + presentPerson() + ' ' + presentVerb();
}

function pastRel() {
    return 'your ' + pastPerson() + ' ' + pastVerb();
}

function presentPerson() {
    let result;
    const words = ['steed', 'king', 'first-born'];
    result = words[mod['present-person'] % 3];
    mod['present-person']++;
    return result;
}

function pastPerson() {
    let result;
    const words = ['mother', 'father', 'grandmother', 'grandfather', 'godfather'];
    result = words[mod['past-person'] % 5];
    mod['past-person']++;
    return result;
}

function noun() {
    let result;
    const words = [
        'hamster', 'coconut', 'duck', 'herring', 'newt',
        'peril', 'chicken', 'vole', 'parrot', 'mouse', 'twit'
    ];
    result = words[mod['noun'] % 11];
    mod['noun']++;
    return result;
}

function presentVerb() {
    let result;
    const words = ['is', 'masquerades as'];
    result = words[mod['present-verb'] % 2];
    mod['present-verb']++;
    return result;
}

function pastVerb() {
    let result;
    const words = ['was', 'personified'];
    result = words[mod['past-verb'] % 2];
    mod['past-verb']++;
    return result;
}

function article() {
    return 'a';
}

function adjective() {
    let result;
    const words = [
        'silly', 'wicked', 'sordid', 'naughty',
        'repulsive', 'malodorous', 'ill-tempered'
    ];
    result = words[mod['adjective'] % 7];
    mod['adjective']++;
    return result;
}

function adverb() {
    let result;
    const words = [
        'conspicuously', 'categorically', 'positively',
        'cruelly', 'incontrovertibly'
    ];
    result = words[mod['adverb'] % 5];
    mod['adverb']++;
    return result;
}

function caps(word) {
    return word[0].toUpperCase() + word.slice(1);
}