const enum Evenness {
    Odd,
    Even,
}

export const iqTest = (numbers: string): number => {
    const splitted = numbers.split(" ");
    let currentIndex = 1;
    let firstEven = true;
    let indexEven = 1;
    let firstOdd = true;
    let indexOdd = 1;
    let whatReturn = Evenness.Odd;
    for (const num of splitted) {
        if (Number(num) % 2 === 0) {
            if (firstEven) {
                indexEven = currentIndex;
                firstEven = false;
            }
        } else {
            if (firstOdd) {
                indexOdd = currentIndex;
                firstOdd = false;
            } else {
                whatReturn = Evenness.Even;
            }
        }
        currentIndex++;
    }

    return (whatReturn === Evenness.Even) ? indexEven : indexOdd;
};
