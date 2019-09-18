/**
 * Megan Barone
 * mab0126
 * project4_mab0126.cpp
 *Compiled using:  g++ project4_mab0126.cpp -std=c++11
 * This is testing version- comment out define (below) to run regular version.
 *
 */
#include <iostream>
#include <string>
#include <sstream>


using namespace std;
#define UNIT_TESTING
//Comment out above statement to test regular version.


    /**
     * Creates a TriviaNode structure.
     * q is for question.
     * a is for answer.
     * p is for points.
     */
    struct TriviaNode {
        string q;
        string a;
        int p;
        TriviaNode *next;

    };
    typedef TriviaNode* ptr_node;
    ptr_node list = NULL;

    /**
     * Adds a node to the beginning of a linked list.
     * @param list is linked list being added to.
     * @param quest is question for node being added.
     * @param ans is answer for node being added.
     * @param pts is points for node being added.
     */
    void addNode(ptr_node& list, string quest, string ans, int pts) {
        ptr_node node = new TriviaNode;
        node->q = quest;
        node->a = ans;
        node->p = pts;

        if (list == NULL) {
            list = node;
            list->next = NULL;
        }
        else {
            node -> next = list;
            list = node;
        }
    }

    /**
     * Prompts user to enter question, answer, and points.
     * Creates a node using these and adds it to the linked list.
     */
    void getQuestions() {
        string question;
        string answer;
        char con;
        string playerAnswer;
        int points;
        cout << "Enter a question: ";
        getline(cin, question);

        cout << "Enter an answer: ";
        getline(cin, answer);

        cout << "Enter award points: ";
        cin >> points;
        addNode(list, question, answer, points);
        cout << "Continue? (Y/N): ";
        cin >> con;
        cin.ignore();

            if (con == 'Y' || con == 'y') {
                getQuestions();
            }
    }

    /**
     * Hard codes 3 trivia questions into the linked list.
     */
    void TriviaExample() {
        TriviaNode node1;
        TriviaNode node2;
        TriviaNode node3;
        string question = "How long was the shortest war on record? (Hint: how many minutes)";
        string answer = "38";
        int points = 100;
        string question2 = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
        string answer2 = "Bank of Italy";
        int points2 = 50;
        string question3 = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
        string answer3 = "Wii Sports";
        int points3 = 20;
        addNode(list, question3, answer3, points3);
        addNode(list, question2, answer2, points2);
        addNode(list, question, answer, points);


    }

    /**
     * Asks user questions in list and compares user answer to correct answer.
     * @param listname is linked list.
     * @param length is how many questions to be asked.
     * @return returns 1 for failure (warning or wrong answer) or 0 for success (correct answer).
     */
    int askQuestions(ptr_node& listname, int length) {
        int success = 1;
        if (length == 0) {
            cout << "Warning-- must ask at least one trivia question.\n";
            return success;
        }
        else {
            string userAnswer;
            int totalPoints = 0;

            int listLength = 0;

            ptr_node temp = listname;
            while (temp != NULL) {
                listLength++;
                temp = temp->next;
            }
            if (length > listLength) {
                cout << "Warning-- only " << listLength << " trivia questions in the list.\n";
                return success;
            }
            temp = listname;
            for(int i = 0; i < length; i++){

                cout << "Question: " << temp->q << "\n";
                cout << "Answer: ";
                getline(cin, userAnswer);
                if (userAnswer == temp->a) {
                    totalPoints += temp->p;
                    success = 0;
                    cout << "Your answer is correct. You receive " << temp->p << " points.\n";
                } else {
                    cout << "Your answer is wrong. The answer is: " << temp->a << "\n";
                    success = 1;

                }
                temp = temp->next;

            }
            cout << "Your total points: " << totalPoints << "\n";
            return success;
        }

    }
    /**
     * Test driver for askQuestions method.
     */
    void testAskQuestions() {
        TriviaExample();
        cout << "*** This is a debugging version ***\n";
        cout << "Unit Test Case 1: Ask no question. The program should give a warning message.\n";
        askQuestions(list, 0);

        cout << "\nUnit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer.\n";
        if (askQuestions(list, 1) == 1) {
            cout << "Case passed...\n";
        }
        else {
            cout << "Case failed...\n";
        }
        cout << "\nUnit Test Case 2.2: Ask 1 question in the linked list. The tester enters an correct answer.\n";
        if (askQuestions(list, 1) == 0) {
            cout << "Case passed...\n";
        }
        else {
            cout << "Case failed...\n";
        }
        cout << "\nUnit Testing Case 3: Ask all the questions in the linked list.\n";
        askQuestions(list, 3);
        cout << "\nUnit Testing Case 4: Ask five questions in the linked list.\n";
        askQuestions(list, 5);
        cout << "\n*** End of Debugging Version ***\n";



    }

    /**
     * Main method.
     * Calls test driver if defined.
     * Displays trivia game otherwise.
     * @return 0
     */
    int main() {
#ifdef UNIT_TESTING
        testAskQuestions();
#else
        int totalPoints = 0;
        cout << "*** Welcome to Megan's trivia quiz game! ***\n";

        getQuestions();

        string question = "Who was the first president of the United States?";
        string answer = "George Washington";
        int points = 10;
        addNode(list, question, answer, points);
        string question2 = "What is the capital of Uruguay?";
        string answer2 = "Montevideo";
        int points2 = 25;
        addNode(list, question2, answer2, points2);
        TriviaExample();
        for(ptr_node temp = list; temp != NULL; temp = temp->next){
            string userAnswer;
            cout << "\nQuestion: " << temp->q << "\n";
            cout << "Answer: ";
            getline(cin, userAnswer);
            if (userAnswer == temp->a) {
                cout << "Your answer is correct. You receive " << temp->p << " points.\n";
                totalPoints += temp->p;

            } else {
                cout << "Your answer is wrong. The answer is: " << temp->a << "\n";

            }

        }

        cout << "\nYour total points: " << totalPoints;
        cout << "\n\n*** Thank you for playing the trivia quiz game. Goodbye! ***\n";
        return 0;

#endif

    }









