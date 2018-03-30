import { iqTest } from "../src/solution";

describe("iqTest", () => {
    it('should return 3 when input is "2 4 7 8 10"', () => {
        const expected = 3;
        expect(iqTest("2 4 7 8 10"))
            .toEqual(expected);
    });

    it('should return 1 when input is "1 2 2"', () => {
        const expected = 1;
        expect(iqTest("1 2 2"))
            .toEqual(expected);
    });

    it('should return 4 when input is "1 1 1 2"', () => {
        const expected = 4;
        expect(iqTest("1 1 1 2"))
            .toEqual(expected);
    });

    it('should return 5 when input is "2 4 8 10 7"', () => {
        const expected = 5;
        expect(iqTest("2 4 8 10 7"))
            .toEqual(expected);
    });
});
