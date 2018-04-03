export const encrypt = (text: string, n: number): string => {
    if (n <= 0) {
        return text;
    }

    let res = "";
    for (let i = 1; i < text.length; i += 2) {
        res += text[i];
    }
    for (let i = 0; i < text.length; i += 2) {
        res += text[i];
    }

    return encrypt(res, n - 1);
};

export const decrypt = (encryptedText: string, n: number): string => {
    if (n <= 0) {
        return encryptedText;
    }

    let res = "";
    for (let i = 0; i < encryptedText.length; ++i) {
        if ((i % 2) === 1) {
            res += encryptedText[Math.trunc(i / 2)];
        } else {
            res += encryptedText[Math.trunc(i / 2) + Math.trunc(encryptedText.length / 2)];
        }
    }

    return decrypt(res, n - 1);
};
