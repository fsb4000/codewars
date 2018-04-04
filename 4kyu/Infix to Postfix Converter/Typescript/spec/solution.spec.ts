import { toPostfix } from "../src/solution";

describe("toPostfix", () => {
    it('should return "34+" when input is "3+4"', () => {
        const expected = "34+";
        const actual = toPostfix("3+4");
        expect(actual)
            .toEqual(expected);
    });

    it('should return "342*15-2^/+" when input is "3+4*2/(1-5)^2"', () => {
        const expected = "342*15-2^/+";
        const actual = toPostfix("3+4*2/(1-5)^2");
        expect(actual)
            .toEqual(expected);
    });

    it('should return "275*+" when input is "2+7*5"', () => {
        const expected = "275*+";
        const actual = toPostfix("2+7*5");
        expect(actual)
            .toEqual(expected);
    });

    it('should return "33*71+/" when input is "3*3/(7+1)"', () => {
        const expected = "33*71+/";
        const actual = toPostfix("3*3/(7+1)");
        expect(actual)
            .toEqual(expected);
    });

    it('should return "562-9*+371-^+" when input is "5+(6-2)*9+3^(7-1)"', () => {
        const expected = "562-9*+371-^+";
        const actual = toPostfix("5+(6-2)*9+3^(7-1)");
        expect(actual)
            .toEqual(expected);
    });

    it('should return "54-1-95/2/+71/7/-" when input is "(5-4-1)+9/5/2-7/1/7"', () => {
        const expected = "54-1-95/2/+71/7/-";
        const actual = toPostfix("(5-4-1)+9/5/2-7/1/7");
        expect(actual)
            .toEqual(expected);
    });
});
