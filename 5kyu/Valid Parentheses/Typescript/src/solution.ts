export const validParentheses = (parens: string): boolean => {
    let brackets = 0;
    for (let i = 0; i < parens.length; ++i) {
        const c = parens.charAt(i);
        if (c === "(") {
            ++brackets;
        } else if (c === ")") {
            --brackets;
        }
        if (brackets < 0) {
            return false;
        }
    }

    return brackets === 0;
};
