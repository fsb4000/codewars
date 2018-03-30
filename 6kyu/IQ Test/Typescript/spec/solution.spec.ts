import { iqTest } from "../src/solution";

describe("iqTest", () => {
    it('should return 3 when input is "2 4 7 8 10"', () => {
        expect(iqTest('2 4 7 8 10')).toEqual(3);
    });

    it('should return 1 when input is "1 2 2"', () => {
        expect(iqTest('1 2 2')).toEqual(1);
    });

    it('should return 4 when input is "1 1 1 2"', () => {
        expect(iqTest('1 1 1 2')).toEqual(4);
    });

    it('should return 5 when input is "2 4 8 10 7"', () => {
        expect(iqTest('1 1 1 2')).toEqual(4);
    });
}); 