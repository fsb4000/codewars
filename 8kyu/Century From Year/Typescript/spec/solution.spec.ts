import { centuryFromYear } from "../src/solution";

const myAssert = (condition: boolean) => {
    if (!condition) {
        throw new Error("assertion failed");
    }
};

const modelSolution = (year: number): number => {
    myAssert(year > 0);

    const truncedYear = Math.trunc(year);
    if (truncedYear % 100 === 0) {
        return Math.trunc(truncedYear / 100);
    }

    return Math.trunc(truncedYear / 100) + 1;
};

const randomInt = (min: number, max: number): number => Math.floor(Math.random() * (max - min + 1)) + min;

describe("centuryFromYear", () => {
    it("should return 18 when input is 1705", () => {
        const expected = 18;
        const actual = centuryFromYear(1705);

        expect(actual).toEqual(expected);
    });

    it("should return 19 when input is 1900", () => {
        const expected = 19;
        const actual = centuryFromYear(1900);

        expect(actual).toEqual(expected);
    });

    it("should return 17 when input is 1601", () => {
        const expected = 17;
        const actual = centuryFromYear(1601);

        expect(actual).toEqual(expected);
    });

    it("should return 20 when input is 2000", () => {
        const expected = 20;
        const actual = centuryFromYear(2000);

        expect(actual).toEqual(expected);
    });

    it("should passes some random tests", () => {
        for (let i = 0; i < 100; ++i) {
            const year = randomInt(1, 1000000);
            const expected = modelSolution(year);
            const actual = centuryFromYear(year);

            expect(actual).toEqual(expected);
        }
    });
});
