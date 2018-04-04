const isNumber = (maybeNum: string): boolean => !isNaN(Number(maybeNum));

const isOperator = (maybeOp: string): boolean => {
    switch (maybeOp) {
        case "+":
        case "-":
        case "*":
        case "/":
        case "^": return true;
        default: return false;
    }
};

const isLeftAssociativity = (op: string): boolean => {
    if (op === "^") {
        return false;
    }

    return true;
};

const getOperatorPriority = (op: string): number => {
    switch (op) {
        case "(": return 0;
        case "+": return 1;
        case "-": return 1;
        case "*": return 2;
        case "/": return 2;
        case "^": return 3;
        default: throw new Error("getOperatorPriority: op is not a operator");
    }
};

export const toPostfix = (infix: string): string => {
    const func = new Array<string>();
    let res = "";
    for (let i = 0; i < infix.length; ++i) {
        const c = infix.charAt(i);
        if (isNumber(c)) {
            res += c;
        } else if (c === "(") {
            func.push(c);
        } else if (c === ")") {
            while (func[func.length - 1] !== "(") {
                res += func.pop();
            }
            func.pop();
        } else if (isOperator(c)) {
            if (func.length !== 0) {
                if (isLeftAssociativity(c)) {
                    while ((func.length !== 0) &&
                        getOperatorPriority(c) <= getOperatorPriority(func[func.length - 1])) {
                        res += func.pop();
                    }
                } else {
                    while ((func.length !== 0) &&
                        getOperatorPriority(c) < getOperatorPriority(func[func.length - 1])) {
                        res += func.pop();
                    }
                }
            }
            func.push(c);
        }
    }
    while ((func.length !== 0)) {
        res += func.pop();
    }

    return res;
};
