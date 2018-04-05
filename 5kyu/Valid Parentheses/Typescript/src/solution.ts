export const validParentheses = (parens: string): boolean => {
    let brackets = 0;
    for (const c of parens) {
        if (c === "(") {
            ++brackets;
        } else if (c === ")") {
            --brackets;
            if (brackets < 0) {
                return false;
            }
        }
    }

    return brackets === 0;
};
