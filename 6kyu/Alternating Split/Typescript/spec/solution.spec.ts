import { decrypt, encrypt } from "../src/solution";

describe("decrypt", () => {
    it('should return "This is a test!" when input is "This is a test!" -1', () => {
        const expected = "This is a test!";
        const actual = decrypt("This is a test!", -1);
        expect(actual)
            .toEqual(expected);
    });

    it('should return "This is a test!" when input is "This is a test!" 0', () => {
        const expected = "This is a test!";
        const actual = decrypt("This is a test!", 0);
        expect(actual)
            .toEqual(expected);
    });

    it('should return "This is a test!" when input is "hsi  etTi sats!" 1', () => {
        const expected = "This is a test!";
        const actual = decrypt("hsi  etTi sats!", 1);
        expect(actual)
            .toEqual(expected);
    });

    it('should return "This is a test!" when input is "s eT ashi tist!" 2', () => {
        const expected = "This is a test!";
        const actual = decrypt("s eT ashi tist!", 2);
        expect(actual)
            .toEqual(expected);
    });

    it('should return "This is a test!" when input is " Tah itse sits!" 3', () => {
        const expected = "This is a test!";
        const actual = decrypt(" Tah itse sits!", 3);
        expect(actual)
            .toEqual(expected);
    });

    it('should return "This is a test!" when input is "This is a test!" 4', () => {
        const expected = "This is a test!";
        const actual = decrypt("This is a test!", 4);
        expect(actual)
            .toEqual(expected);
    });

    it('should return "" when input is "" 3', () => {
        const expected = "";
        const actual = decrypt("", 3);
        expect(actual)
            .toEqual(expected);
    });
});

describe("encrypt", () => {
    it('should return "This is a test!" when input is "This is a test!" -1', () => {
        const expected = "This is a test!";
        const actual = encrypt("This is a test!", -1);
        expect(actual)
            .toEqual(expected);
    });

    it('should return "This is a test!" when input is "This is a test!" 0', () => {
        const expected = "This is a test!";
        const actual = encrypt("This is a test!", 0);
        expect(actual)
            .toEqual(expected);
    });

    it('should return "hsi  etTi sats!" when input is "This is a test!" 1', () => {
        const expected = "hsi  etTi sats!";
        const actual = encrypt("This is a test!", 1);
        expect(actual)
            .toEqual(expected);
    });

    it('should return "s eT ashi tist!" when input is "This is a test!" 2', () => {
        const expected = "s eT ashi tist!";
        const actual = encrypt("This is a test!", 2);
        expect(actual)
            .toEqual(expected);
    });

    it('should return " Tah itse sits!" when input is "This is a test!" 3', () => {
        const expected = " Tah itse sits!";
        const actual = encrypt("This is a test!", 3);
        expect(actual)
            .toEqual(expected);
    });

    it('should return "This is a test!" when input is "This is a test!" 4', () => {
        const expected = "This is a test!";
        const actual = encrypt("This is a test!", 4);
        expect(actual)
            .toEqual(expected);
    });

    it('should return "" when input is "" 3', () => {
        const expected = "";
        const actual = encrypt("", 3);
        expect(actual)
            .toEqual(expected);
    });
});
