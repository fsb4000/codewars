const myAssert = (condition: boolean) => {
    if (!condition) {
        throw new Error("assertion failed");
    }
};

const fact = (n: number): number => {
    let res = 1;
    for (let i = 1; i <= n; ++i) {
        res *= i;
    }

    return res;
};

export const strongNumber = (num: number): string => {
    myAssert(num > 0);

    let temp = num;
    let res = 0;
    while (temp > 0 && res < num) {
        res += fact(temp % 10);
        temp /= 10;
    }
    if (res === num) {
        return "STRONG!!!!";
    }

    return "Not Strong !!";
};
