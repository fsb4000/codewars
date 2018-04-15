import { strongNumber } from "../src/solution";

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

const modelSolution = (num: number): string => {
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

const randomInt = (min: number, max: number): number => Math.floor(Math.random() * (max - min + 1)) + min;

const strong = "STRONG!!!!";
const notStrong = "Not Strong !!";

describe("strongNumber", () => {
    it("should return strong when input is 1", () => {
        const expected = strong;
        const actual = strongNumber(1);

        expect(actual).toEqual(expected);
    });

    it("should return strong when input is 2", () => {
        const expected = strong;
        const actual = strongNumber(2);

        expect(actual).toEqual(expected);
    });

    it("should return strong when input is 145", () => {
        const expected = strong;
        const actual = strongNumber(145);

        expect(actual).toEqual(expected);
    });

    it("should return notStrong when input is 7", () => {
        const expected = notStrong;
        const actual = strongNumber(7);

        expect(actual).toEqual(expected);
    });

    it("should return notStrong when input is 93", () => {
        const expected = notStrong;
        const actual = strongNumber(93);

        expect(actual).toEqual(expected);
    });

    it("should return notStrong when input is 185", () => {
        const expected = notStrong;
        const actual = strongNumber(185);

        expect(actual).toEqual(expected);
    });

    it("should passes some random tests", () => {
        for (let i = 0; i < 100; ++i) {
            const num = randomInt(1, 1000000);
            const expected = modelSolution(num);
            const actual = strongNumber(num);

            expect(actual).toEqual(expected);
        }
    });
});
