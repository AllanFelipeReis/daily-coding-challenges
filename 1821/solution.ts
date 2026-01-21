function squareRoot(n: number, epsilon: number = 0.0000001): number {
    if (n < 0) return NaN;

    if (n === 0 || n === 1) return n;

    let x = n;
    let root: number;

    while (true) {
        root = 0.5 * (x + n / x);

        if (Math.abs(x - root) < epsilon) {
            break;
        }

        x = root;
    }

    return root;
}

// Testes
console.log(squareRoot(9)) // Return 3
console.log(squareRoot(2)) // Return 1.41
console.log(squareRoot(25)) // Return 5