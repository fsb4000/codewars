import * as cheerio from "cheerio";
import * as fetch from "node-fetch";
const URL = "https://www.codewars.com/users/leaderboard";

class User {
    public clan: string;
    public honor: number;
    public name: string;
    public constructor(name: string, clan: string, honor: number) {
        this.name = name;
        this.clan = clan;
        this.honor = honor;
    }
}

export const solution = async () => {
    const res = await fetch.default(URL);
    const body = await res.text();
    const $ = cheerio.load(body);
    const position = new Array<User>();
    $(".leaderboard tr")
        .slice(1, 501)
        .each((i, el) => {
            const $el = $(el);
            const [, , clan, honor] = $el.children().get();
            position[i + 1] = new User($el.data("username") as string, $(clan).text(), Number($(honor).text()));
        });

    return { position };
};
