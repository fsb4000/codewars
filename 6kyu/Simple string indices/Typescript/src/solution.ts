export const solution = (str: string, index: number): number => {
    const openBrace = "(";
    const closeBrace = ")";
    const error = -1;

    if (str.charAt(index) !== openBrace) {
        return error;
    }

    let numberOpenBraces = 1;
    for (let i = index + 1; i < str.length; ++i) {
        switch (str.charAt(i)) {
            case openBrace: {
                ++numberOpenBraces;
                break;
            }
            case closeBrace: {
                --numberOpenBraces;
                break;
            }
            default: {
                // Do nothing
            }
        }

        if (numberOpenBraces === 0) {
            return i;
        }
    }

    return error;
};
