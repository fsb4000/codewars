const myAssert = (condition: boolean) => {
    if (!condition) {
        throw new Error("assertion failed");
    }
};

export const centuryFromYear = (year: number): number => {
    myAssert(year > 0);

    const truncedYear = Math.trunc(year);
    if (truncedYear % 100 === 0) {
        return Math.trunc(truncedYear / 100);
    }

    return Math.trunc(truncedYear / 100) + 1;
};
