function canShift(a: string, b: string): boolean {
    if (a.length !== b.length) {
        return false;
    }

    if (a.length === 0) {
        return true;
    }

    const doubledA = a + a;
    return doubledA.includes(b);
}

console.log(canShift("abcde", "cdeab")); // true
console.log(canShift("abc", "acb"));     // false
console.log(canShift("rotate", "terota")); // true