const myAssert = (condition: boolean) => {
    if (!condition) {
        throw new Error("assertion failed");
    }
};

export const minValue = (values: number[]): number => {
    const numbers = Array<boolean>(10).fill(false);
    for (const value of values) {
        myAssert(value > 0);
        myAssert(value < 10);
        myAssert(Math.trunc(value) === value);
        numbers[value] = true;
    }
    let res = 0;
    for (let i = 1; i < numbers.length; ++i) {
        if (numbers[i]) {
            res = res * 10 + i;
        }
    }

    return res;
};
