import { solution } from "../src/solution";

describe("solution", () => {
    it('should return -1 when input is "0()" 0', () => {
        const expected = -1;
        const actual = solution("0()", 0);
        expect(actual)
            .toEqual(expected);
    });

    it('should return 1 when input is "()" 0', () => {
        const expected = 1;
        const actual = solution("()", 0);
        expect(actual)
            .toEqual(expected);
    });

    it('should return 10 when input is "((1)23(45))(aB)" 0', () => {
        const expected = 10;
        const actual = solution("((1)23(45))(aB)", 0);
        expect(actual)
            .toEqual(expected);
    });

    it('should return 3 when input is "((1)23(45))(aB)" 1', () => {
        const expected = 3;
        const actual = solution("((1)23(45))(aB)", 1);
        expect(actual)
            .toEqual(expected);
    });

    it('should return -1 when input is "((1)23(45))(aB)" 3', () => {
        const expected = -1;
        const actual = solution("((1)23(45))(aB)", 3);
        expect(actual)
            .toEqual(expected);
    });

    it('should return 9 when input is "((1)23(45))(aB)" 6', () => {
        const expected = 9;
        const actual = solution("((1)23(45))(aB)", 6);
        expect(actual)
            .toEqual(expected);
    });

    it('should return 14 when input is "((1)23(45))(aB)" 11', () => {
        const expected = 14;
        const actual = solution("((1)23(45))(aB)", 11);
        expect(actual)
            .toEqual(expected);
    });

    it('should return 28 when input is "(g(At)IO(f)(tM(qk)YF(n)Nr(E)))" 11', () => {
        const expected = 28;
        const actual = solution("(g(At)IO(f)(tM(qk)YF(n)Nr(E)))", 11);
        expect(actual)
            .toEqual(expected);
    });

    it('should return -1 when input is "(g(At)IO(f)(tM(qk)YF(n)Nr(E)))" 28', () => {
        const expected = -1;
        const actual = solution("(g(At)IO(f)(tM(qk)YF(n)Nr(E)))", 28);
        expect(actual)
            .toEqual(expected);
    });

    it('should return 29 when input is "(g(At)IO(f)(tM(qk)YF(n)Nr(E)))" 0', () => {
        const expected = 29;
        const actual = solution("(g(At)IO(f)(tM(qk)YF(n)Nr(E)))", 0);
        expect(actual)
            .toEqual(expected);
    });

    it('should return 22 when input is "(>_(va)`?(h)C(as)(x(hD)P|(fg)))" 19', () => {
        const expected = 22;
        const actual = solution("(>_(va)`?(h)C(as)(x(hD)P|(fg)))", 19);
        expect(actual)
            .toEqual(expected);
    });
});
