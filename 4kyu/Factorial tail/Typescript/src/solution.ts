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

export const zeroes = (base: number, num: number) => countZeros(num, getMultipliers(base));
