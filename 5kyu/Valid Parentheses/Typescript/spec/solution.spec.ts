import { validParentheses } from "../src/solution";

describe("validParentheses", () => {
    it('should return true when input is "()"', () => {
        const expected = true;
        const actual = validParentheses("()");
        expect(actual)
            .toEqual(expected);
    });

    it('should return false when input is "())"', () => {
        const expected = false;
        const actual = validParentheses("())");
        expect(actual)
            .toEqual(expected);
    });

    it('should return false when input is "("', () => {
        const expected = false;
        const actual = validParentheses("(");
        expect(actual)
            .toEqual(expected);
    });

    it('should return false when input is ")(()))"', () => {
        const expected = false;
        const actual = validParentheses(")(()))");
        expect(actual)
            .toEqual(expected);
    });

    it('should return true when input is "(())((()())())"', () => {
        const expected = true;
        const actual = validParentheses("(())((()())())");
        expect(actual)
            .toEqual(expected);
    });
});
