import { solution } from "../src/solution";

describe("solution", () => {
    it("should have a size of 500", (done) => {
        solution().then((leaderboard) => {
            expect(leaderboard.position.length).toBe(501);
            done();
        }).catch((reject: Error) => {
            fail();
        });
    });

    it("should contain the correct names", (done) => {
        solution().then((leaderboard) => {
            // Since these are hard coded, you should substitute with the current top 5
            expect(leaderboard.position[1].name).toBe("g964");
            expect(leaderboard.position[2].name).toBe("myjinxin2015");
            expect(leaderboard.position[3].name).toBe("Voile");
            expect(leaderboard.position[4].name).toBe("SteffenVogel_79");
            expect(leaderboard.position[5].name).toBe("smile67");
            done();
        }).catch((reject: Error) => {
            fail();
        });
    });

    it("should contain the correct clan", (done) => {
        solution().then((leaderboard) => {
            // Since these are hard coded, you should substitute with the current top 5
            expect(leaderboard.position[1].clan).toBe("None");
            expect(leaderboard.position[2].clan).toBe("中国 长垣");
            expect(leaderboard.position[3].clan).toBe("Gensokyo");
            expect(leaderboard.position[4].clan).toBe("CSV - SLayer");
            expect(leaderboard.position[5].clan).toBe("PropertyExpert, Germany");
            done();
        }).catch((reject: Error) => {
            fail();
        });
    });

    it("should contain the correct honor", (done) => {
        solution().then((leaderboard) => {
            // Since these are hard coded, you should substitute with the current top 5
            expect(leaderboard.position[1].honor).toBeGreaterThan(110000);
            expect(leaderboard.position[2].honor).toBeGreaterThan(110000);
            expect(leaderboard.position[3].honor).toBeGreaterThan(60000);
            expect(leaderboard.position[4].honor).toBeGreaterThan(55000);
            expect(leaderboard.position[5].honor).toBeGreaterThan(50000);
            done();
        }).catch((reject: Error) => {
            fail();
        });
    });
});
