function solution(numbers) {
    const sum = numbers.reduce((total, plus) => total + plus);
    return 45 - sum;
}