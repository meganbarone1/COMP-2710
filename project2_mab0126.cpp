/**
 * Megan Barone
 * mab0126
 * project2_mab0126.cpp
 * compile using g++: g++ project2_mab0126.cpp -o project2_mab0126
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctime>

using namespace std;

class project_mab0126 {

private:

    static const int aaronAccuracy = 3;
    static const int bobAccuracy = 2;
    static const int charlieAccuracy = 1;
    bool isFirstRound;
public:

    void initIsFirstRound() {
        isFirstRound = true;
    }
    bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
        return (A_alive && B_alive) || (B_alive && C_alive) || (A_alive && C_alive);

    }

    void test_at_least_two_alive() {
        cout << "Unit Testing 1: Function - at_least_two_alive()\n";
        cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
        assert(at_least_two_alive(true, true, true));
        cout << "\tCase passed ...\n";
        cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
        assert(at_least_two_alive(false, true, true));
        cout << "\tCase passed ...\n";
        cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
        assert(at_least_two_alive(true, false, true));
        cout << "\tCase passed ...\n";
        cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
        assert(at_least_two_alive(true, true, false));
        cout << "\tCase passed ...\n";
        cout << "\tCase 5: Aaron alive, Bob dead, Charlie dead\n";
        assert(!at_least_two_alive(true, false, false));
        cout << "\tCase passed ...\n";
        cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
        assert(!at_least_two_alive(false, true, false));
        cout << "\tCase passed ...\n";
        cout << "\tCase 7: Aaron dead, Bob dead, Charlie alive\n";
        assert(!at_least_two_alive(false, false, true));
        cout << "\tCase passed ...\n";
    }

    void Aaron_shoots1(bool &B_alive, bool &C_alive) {
        int shoot_target_result = rand() % aaronAccuracy;
        if (shoot_target_result == 0) {
            if (C_alive) {
                C_alive = false;
            }
            else if (B_alive) {
                B_alive = false;
            }

        }
    }

    void test_Aaron_shoots1() {
        cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
        bool B_alive = true;
        bool C_alive = true;
        cout << "\tCase 1: Bob alive, Charlie alive\n";
        cout << "\t\tAaron is shooting at Charlie\n";
        Aaron_shoots1(B_alive, C_alive);
        if (C_alive) {
            cout << "\t\tAaron misses.\n";
        }
        if (!C_alive) {
            cout << "\t\tCharlie is dead.\n";
        }
        B_alive = false;
        C_alive = true;
        cout << "\tCase 2: Bob dead, Charlie alive\n";
        cout << "\t\tAaron is shooting at Charlie\n";
        Aaron_shoots1(B_alive, C_alive);
        if (C_alive) {
            cout << "\t\tAaron misses.\n";
        }
        if (!C_alive) {
            cout << "\t\tCharlie is dead.\n";
        }
        B_alive = true;
        C_alive = false;
        cout << "\tCase 3: Bob alive, Charlie dead\n";
        cout << "\t\tAaron is shooting at Bob\n";
        Aaron_shoots1(B_alive, C_alive);
        if (B_alive) {
            cout << "\t\tAaron misses.\n";
        }
        if (!B_alive) {

            cout << "\t\tCharlie is dead.\n";
        }
    }

    void Bob_shoots(bool &A_alive, bool &C_alive) {
        int shoot_target_result = rand() % bobAccuracy;
        if (shoot_target_result == 0) {
            if (C_alive) {
                C_alive = false;
                return;
            }
            A_alive = false;

        }
    }

    void test_Bob_shoots() {
        cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
        bool A_alive = true;
        bool C_alive = true;
        cout << "\tCase 1: Aaron alive, Charlie alive\n";
        cout << "\t\tBob is shooting at Charlie\n";
        Bob_shoots(A_alive, C_alive);
        if (C_alive) {
            cout << "\t\tBob misses.\n";
        }
        if (!C_alive) {
            cout << "\t\tCharlie is dead.\n";
        }

        A_alive = false;
        C_alive = true;
        cout << "\tCase 2: Aaron dead, Charlie alive\n";
        cout << "\t\tBob is shooting at Charlie\n";
        Bob_shoots(A_alive, C_alive);
        if (C_alive) {
            cout << "\t\tBob misses.\n";
        }
        if (!C_alive) {
            cout << "\t\tCharlie is dead.\n";
        }

        A_alive = true;
        C_alive = false;
        cout << "\tCase 3: Aaron alive, Charlie dead\n";
        cout << "\t\tBob is shooting at Aaron\n";
        Bob_shoots(A_alive, C_alive);
        if (A_alive) {
            cout << "\t\tBob misses.\n";
        }
        if (!A_alive) {
            cout << "\t\tAaron is dead.\n";
        }


    }

    void Charlie_shoots(bool &A_alive, bool &B_alive) {
        int shoot_target_result = rand() % charlieAccuracy;
        if (B_alive && shoot_target_result == 0) {
            B_alive = false;
            return;
        }
        A_alive = false;
    }

    void test_Charlie_shoots() {
        cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

        bool A_alive = true;
        bool B_alive = true;
        cout << "\tCase 1: Aaron alive, Bob alive\n";
        cout << "\t\tCharlie is shooting at Bob\n";
        Charlie_shoots(A_alive, B_alive);
        if (!B_alive) {
            cout << "\t\tBob is dead.\n";
        }

        A_alive = false;
        B_alive = true;
        cout << "\tCase 2: Aaron dead, Bob alive\n";
        cout << "\t\tCharlie is shooting at Bob\n";
        Charlie_shoots(A_alive, B_alive);
        if (!B_alive) {
            cout << "\t\tBob is dead.\n";
        }

        A_alive = true;
        B_alive = false;
        cout << "\tCase 3: Aaron alive, Bob dead\n";
        cout << "\t\tCharlie is shooting at Aaron\n";
        Charlie_shoots(A_alive, B_alive);
        if (!A_alive) {
            cout << "\t\tAaron is dead.\n";
        }
    }

    void Aaron_shoots2(bool &B_alive, bool &C_alive) {
        if (isFirstRound) {
            B_alive = true;
            C_alive = true;
            isFirstRound = false;
        }
        else {
            Aaron_shoots1(B_alive, C_alive);
            }

    }


    void test_Aaron_shoots2() {
        cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";

        bool B_alive = true;
        bool C_alive = true;
        cout << "\tCase 1: Bob alive, Charlie alive\n";
        cout << "\t\tAaron intentionally misses his first shot\n";
        Aaron_shoots2(B_alive, C_alive);
        if (B_alive && C_alive) {
            cout << "\t\tBoth Bob and Charlie are alive.\n";
        }

        B_alive = false;
        C_alive = true;
        cout << "\tCase 2: Bob dead, Charlie alive\n";
        cout << "\t\tAaron is shooting at Charlie\n";
        Aaron_shoots2(B_alive, C_alive);
        if (C_alive) {
            cout << "\t\tAaron misses.\n";
        }
        if (!C_alive) {
            cout << "\t\tCharlie is dead.\n";
        }
        B_alive = true;
        C_alive = false;
        cout << "\tCase 3: Bob alive, Charlie dead\n";
        cout << "\t\tAaron is shooting at Bob\n";
        Aaron_shoots2(B_alive, C_alive);
        if (B_alive) {
            cout << "\t\tAaron misses.\n";
        }
        if (!B_alive) {
            cout << "\t\tBob is dead.\n";
        }
    }
};


    int main() {
        srand(time(0));
        const int ITERATIONS = 10000;
        project_mab0126 p = project_mab0126();
        p.initIsFirstRound();
        bool aaron = true;

        bool bob = true;
        bool charlie = true;
        int aaronWinCount = 0;
        int bobWinCount = 0;
        int charlieWinCount = 0;
        cout << "*** Welcome to Megan's Duel Simulator ***\n";
        p.test_at_least_two_alive();
        cout << "Press enter to continue...\n";
        getchar();
        p.test_Aaron_shoots1();
        cout << "Press enter to continue...\n";
        getchar();
        p.test_Bob_shoots();
        cout << "Press enter to continue...\n";
        getchar();
        p.test_Charlie_shoots();
        cout << "Press enter to continue...\n";
        getchar();
        p.test_Aaron_shoots2();
        cout << "Press enter to continue...\n";
        getchar();
        cout << "Ready to test strategy 1 (run 10000 times): \n";
        cout << "Press enter to continue...\n";
        getchar();

        for (int i = 0; i < ITERATIONS; i++) {
            while (p.at_least_two_alive(aaron, bob, charlie)) {
                if (aaron) {
                    p.Aaron_shoots1(bob, charlie);
                }
                if (bob) {
                    p.Bob_shoots(aaron, charlie);
                }
                if (charlie) {
                    p.Charlie_shoots(aaron, bob);
                }
            }
            if (aaron) {
                aaronWinCount++;
            }
            else if (bob) {
                bobWinCount++;
            }
            else if (charlie) {
                charlieWinCount++;
            }


            aaron = true;
            bob = true;
            charlie = true;
        }
        double aaronWinPercent = (double(aaronWinCount) / ITERATIONS) * 100;
        double bobWinPercent = (double(bobWinCount) / ITERATIONS) * 100;
        double charlieWinPercent = (double(charlieWinCount) / ITERATIONS) * 100;
        cout << "\nAaron won " << aaronWinCount << "/" << ITERATIONS <<  " duels or " << aaronWinPercent << "%\n";
        cout << "Bob won " << bobWinCount << "/" << ITERATIONS << " duels or " << bobWinPercent << "%\n";
        cout << "Charlie won " << charlieWinCount << "/10000 duels or " << charlieWinPercent << "%\n";

        int aaron1Wins = aaronWinCount;
        aaronWinCount = 0;
        bobWinCount = 0;
        charlieWinCount = 0;
        cout << "\nReady to test strategy 2 (run 10000 times): \n";
        cout << "Press enter to continue...\n";
        getchar();

        for (int i = 0; i < ITERATIONS; i++) {
            p.initIsFirstRound();
            while (p.at_least_two_alive(aaron, bob, charlie)) {
                if (aaron) {
                    p.Aaron_shoots2(bob, charlie);
                }
                if (bob) {
                    p.Bob_shoots(aaron, charlie);
                }
                if (charlie) {
                    p.Charlie_shoots(aaron, bob);
                }
            }
            if (aaron) {
                aaronWinCount++;
            }
            if (bob) {
                bobWinCount++;
            }
            if (charlie) {
                charlieWinCount++;
            }
            aaron = true;
            bob = true;
            charlie = true;
        }
        double aaronWinPercent2 = (double(aaronWinCount) / ITERATIONS) * 100;
        double bobWinPercent2 = (double(bobWinCount) / ITERATIONS) * 100;
        double charlieWinPercent2 = (double(charlieWinCount) / ITERATIONS) * 100;
        cout << "\nAaron won " << aaronWinCount << "/" << ITERATIONS << " duels or " << aaronWinPercent2 << "%\n";
        cout << "Bob won " << bobWinCount << "/" << ITERATIONS << " duels or " << bobWinPercent2 << "%\n";
        cout << "Charlie won " << charlieWinCount << "/" << ITERATIONS << " duels or " << charlieWinPercent2 << "%\n\n";
        int aaron2Wins = aaronWinCount;

        if (aaron1Wins > aaron2Wins) {
            cout << "Strategy 1 is better than strategy 2.\n";
        }
        else if (aaron1Wins < aaron2Wins) {
            cout << "Strategy 2 is better than strategy 1.\n";
        }

        return 0;
    }

