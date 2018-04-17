import { zeroes } from "../src/solution";

describe("zeroes, fixed tests", () => {
    it("should return 2 when input is (10,10)", () => {
        const expected = 2;
        const actual = zeroes(10, 10);

        expect(actual).toEqual(expected);
    });

    it("should return 3 when input is (16,16)", () => {
        const expected = 3;
        const actual = zeroes(16, 16);

        expect(actual).toEqual(expected);
    });

    it("should return 2 when input is (40,10)", () => {
        const expected = 2;
        const actual = zeroes(40, 10);

        expect(actual).toEqual(expected);
    });

    it("should return 0 when input is (17,16)", () => {
        const expected = 0;
        const actual = zeroes(17, 16);

        expect(actual).toEqual(expected);
    });

    it("should return 8 when input is (7,50)", () => {
        const expected = 8;
        const actual = zeroes(7, 50);

        expect(actual).toEqual(expected);
    });

    it("should return 6 when input is (100,50)", () => {
        const expected = 6;
        const actual = zeroes(100, 50);

        expect(actual).toEqual(expected);
    });

    it("should return 10 when input is (12,26)", () => {
        const expected = 10;
        const actual = zeroes(12, 26);

        expect(actual).toEqual(expected);
    });

    it("should return 11 when input is (12,27)", () => {
        const expected = 11;
        const actual = zeroes(12, 27);

        expect(actual).toEqual(expected);
    });

    it("should return 12 when input is (12,28)", () => {
        const expected = 12;
        const actual = zeroes(12, 28);

        expect(actual).toEqual(expected);
    });

    it("should return 14 when input is (12,32)", () => {
        const expected = 14;
        const actual = zeroes(12, 32);

        expect(actual).toEqual(expected);
    });

    it("should return 15 when input is (12,33)", () => {
        const expected = 15;
        const actual = zeroes(12, 33);

        expect(actual).toEqual(expected);
    });

    it("should return 10 when input is (80,49)", () => {
        const expected = 10;
        const actual = zeroes(80, 49);

        expect(actual).toEqual(expected);
    });

    it("should return 11 when input is (80,50)", () => {
        const expected = 11;
        const actual = zeroes(80, 50);

        expect(actual).toEqual(expected);
    });

    it("should return 12 when input is (80,52)", () => {
        const expected = 12;
        const actual = zeroes(80, 52);

        expect(actual).toEqual(expected);
    });

    it("should return 5 when input is (17,100)", () => {
        const expected = 5;
        const actual = zeroes(17, 100);

        expect(actual).toEqual(expected);
    });

    it("should return 5 when input is (170,100)", () => {
        const expected = 5;
        const actual = zeroes(170, 100);

        expect(actual).toEqual(expected);
    });

    it("should return 5 when input is (221,100)", () => {
        const expected = 5;
        const actual = zeroes(221, 100);

        expect(actual).toEqual(expected);
    });

    it("should return 2^19 -1 when input is (2, 2^19)", () => {
        const b19 = Math.pow(2, 19);
        const expected = b19 - 1;
        const actual = zeroes(2, b19);

        expect(actual).toEqual(expected);
    });

    it("should return 0 when input is (251, 250)", () => {
        const expected = 0;
        const actual = zeroes(251, 250);

        expect(actual).toEqual(expected);
    });

    it("should return 124 when input is (256, 1000)", () => {
        const expected = 124;
        const actual = zeroes(256, 1000);

        expect(actual).toEqual(expected);
    });

    it("should return 249998 when input is (10, 1e6)", () => {
        const expected = 249998;
        const actual = zeroes(10, 1000000);

        expect(actual).toEqual(expected);
    });

    it("should return 124999 when input is (256, 1e6)", () => {
        const expected = 124999;
        const actual = zeroes(256, 1000000);

        expect(actual).toEqual(expected);
    });
});

describe("zeroes, random tests", () => {
    class Multiplier {
        public num = 0;
        public quantity = 0;
        public constructor(num: number, quantity: number) {
            this.num = num;
            this.quantity = quantity;
        }
    }

    const myAssert = (condition: boolean) => {
        if (!condition) {
            throw new Error("assertion failed");
        }
    };

    const isPrime = (n: number) => {
        myAssert(n >= 1);
        if (n === 1) {
            return false;
        }
        if (n === 2) {
            return true;
        }
        if (n % 2 === 0) {
            return false;
        }
        for (let i = 3; i * i <= n; i += 2) {
            if (n % i === 0) {
                return false;
            }
        }

        return true;
    };

    const getPrimes = (max: number) => {
        const res = new Array<number>();
        for (let i = 2; i <= max; ++i) {
            if (isPrime(i)) {
                res.push(i);
            }
        }

        return res;
    };

    const getMultipliers = (n: number) => {
        const primes = getPrimes(n);
        const res = new Array<Multiplier>();
        for (const prime of primes) {
            let temp = n;
            let q = 0;
            while (temp % prime === 0) {
                ++q;
                temp = temp / prime;
            }
            if (q !== 0) {
                res.push(new Multiplier(prime, q));
            }
        }

        return res;
    };

    const countZeros = (n: number, multipliers: Multiplier[]) => {
        const res = new Array<Multiplier>();
        for (const m of multipliers) {
            let multiplier = m.num;
            let q = 0;
            while (Math.trunc(n / multiplier) > 0) {
                q += Math.trunc(n / multiplier);
                multiplier *= m.num;
            }
            res.push(new Multiplier(m.num, Math.trunc(q / m.quantity)));
        }

        return res.reduce((minimal, current) => minimal.quantity < current.quantity ? minimal : current).quantity;
    };

    const modelSolution = (base: number, num: number) => countZeros(num, getMultipliers(base));

    const randomInt = (min: number, max: number): number => Math.floor(Math.random() * (max - min + 1)) + min;

    it("should passes random tests", () => {
        for (let i = 0; i < 100; ++i) {
            const base = randomInt(2, 256);
            const num = randomInt(1000, 10000);
            const expected = modelSolution(base, num);
            const actual = zeroes(base, num);

            expect(actual).toEqual(expected);
        }
    });
});
