function solution(s) {
    const db = {
        'one': 1,
        'two': 2,
        'three': 3,
        'four': 4,
        'five': 5,
        'six': 6,
        'seven': 7,
        'eight': 8,
        'nine': 9,
        'zero': 0
    }

    s = s.replace(/one|two|three|four|five|six|seven|eight|nine|zero/g, (word) => {
        return db[word];
    });

    return parseInt(s);
}