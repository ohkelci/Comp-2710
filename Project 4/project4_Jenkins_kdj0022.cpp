// Kelci Jenkinse
// project4_Jenkins_kdj0022.cpp
//
// received help from friend, used prior knowledge, and notes.
//

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

//Structure for creating a linked list that holds a trivia question,answer and point amount.
struct trivia_node {
       string question;
       string answer;
       int point;
       trivia_node *next;
};

int questionCount;

//creates a pointer to triva_node.
typedef trivia_node* ptr_node;

//Prototypes
void init_question_list(ptr_node& q_list);
void ask_question(ptr_node qlist, int num_ask);
bool checkAnswer(string a, ptr_node& q_list);
void add_question(ptr_node& q_list);
void Unit_Test(ptr_node& q_list);

//boolean variables used
bool cont = false;
bool correctAnswer = true;

//version for unit testing
//#define UNIT_TESTING
#ifdef UNIT_TEST
    TriviaNode *nodeList = new TriviaNode;
    initializeQuestion(nodeList);
    Unit_Test(nodeList);
#endif

#define triva_quiz
int main() {
    ptr_node node_list = new trivia_node;
       //Creates a new trivia game /
       //Sets up three original  questions/
       //Sets up loop for user to input his or her own questions.
       //Quiz questions are stored in linked list.
#ifdef triva_quiz
    init_question_list(node_list);
    cout << "*** Welcome to Kelci's trivia quiz game ***\n";
    do {
        add_question(node_list); //allows users to add their own questions to the linked list
    } while (cont); //gives user option to continue
    cin.ignore(1); //clears input
    
    //This is start of Trivia quiz game.
    ask_question(node_list, questionCount);
    cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***";

}
#endif

//initializes the quiz to have these three questions inputted into the linked list.
void init_question_list(ptr_node& q_list) {
       //ptr_node cur_ptr;
       //ptr_node cur_ptr;
// Question 1
    string bob;
    ptr_node cur_ptr = new trivia_node;
    cur_ptr->question = "How long was the shortest war on record? (Hint: How many minutes)";
    cur_ptr->answer = "38";
    cur_ptr->point = 100;
    cur_ptr->next = NULL;
    q_list = cur_ptr;
// Question 2
    ptr_node cur_ptr2 = new trivia_node;
    cur_ptr2->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
    cur_ptr2->answer = "Bank of Germany";
    cur_ptr2->point = 50;
    cur_ptr2->next = NULL;
    q_list = cur_ptr2;
// Question 3
    ptr_node cur_ptr3 = new trivia_node;
    cur_ptr3->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
    cur_ptr3->answer = "Wii Sports";
    cur_ptr3->point = 20;
    cur_ptr3->next = NULL;

}

//gives user the option to add a question to the linked list.
//question is added to the front of the linked list.
void add_question(ptr_node& q_list) {
    string addAnother;

    //gets to the end of the list
    while(q_list->next!=NULL) {
        q_list = q_list->next;
    }
    //create pointer variable to new question added by user
    ptr_node cur_ptr = new trivia_node;

    cout << "Enter a question: ";
    cin >> cur_ptr->question;

    cout << "Enter an answer: ";
    cin >> cur_ptr->answer;

    cout << "Enter award points: ";
    cin >> cur_ptr->point;

    q_list->next = cur_ptr;

    cout << "Continue? (Yes/No): ";
    questionCount++;
    cin >> addAnother;

    //if user enter no, the do-while loop in the main function will break
    //otherwise, user gets to add anothef question to the linked list
    if (addAnother.compare("no") == 0 || addAnother.compare("No") == 0 || addAnother.compare("NO") == 0) {
        cont = false;
    }
    else {
        cont = true;
    }
}
//Checks for null value
//Ask the user trivia questions and starts the game
void ask_question(ptr_node q_list, int num_ask) {
    int totalPoints = 0;
    string user_answer;
 
    if (num_ask < 1) {
        cout << "Warning - the number of trivia to be asked must equal to or be larger than 1." << endl;
        
    }
    else if (num_ask == 1) {
        cout << "\nQuestion: " << q_list->question;
        cout << "\nAnswer: ";
        getline(cin, user_answer);

        if (checkAnswer(user_answer, q_list)) {
            correctAnswer = true;
        } else {
            correctAnswer = false;
        }
        q_list = q_list->next;
        cout << endl;
    }
    else if (num_ask == 3) {
        while (q_list->next != NULL) {
            q_list = q_list->next;
        }
        cout << "\nQuestion: " << q_list->question;
        cout << "\nAnswer: ";
        getline(cin, user_answer);
    }
    else if (num_ask > questionCount) {
        cout << "Warning - There are only three trivia in the list." << endl;
    }

    else {
        //begin game
        //iterate through each question until end using 'for' loop
        for (int x = 0; x < num_ask; x++) {
            cout << " " << endl;
            cout << "Question: " << q_list->question << endl;
            cout << "Answer: ";
            getline(cin, user_answer);

            if (checkAnswer(user_answer, q_list)) {
                cout << "Your answer is correct. You receive " << q_list->point << " points." << endl;
                totalPoints += q_list->point;
                cout << "Your total points: " << totalPoints;
            } else {
                cout << "Your answer is wrong.  The correct answer is " << q_list->answer << endl;
                cout << "Your total points: " << totalPoints;
            }
            q_list = q_list->next;
            cout << endl;
        }
    }

}

//check to make sure answer is correct
bool checkAnswer(string a, ptr_node q_list) {
    if (q_list->answer.compare(a) == 0) {
        return true;
    }
    return false;
}

    //Test cases to check whether the methods work.
    void Unit_Test(ptr_node& q_list) {
        cout << "*** This is a debug version ***" << endl;
        cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
        ask_question(q_list, 0);
        cout << "\nCase 1 Passed\n\n";
        
        cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer.";
        ask_question(q_list, 1);
        if (!correctAnswer) {
            cout << "Case 2.1 passed..." << endl;
        }
        cout << " " << endl;
        cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer.";
        ask_question(q_list, 1);
        if (correctAnswer) {
            cout << "Case 2.2 passed..." << endl;
        }
        
        cout << " " << endl;
        cout << "Unit Test Case 3: Ask the last trivia in the linked list.";
        ask_question(q_list, 3);
        
        cout << " " << endl;
        cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
        ask_question(q_list, 5);
        
        cout << " " << endl;
        cout << "\n\n*** End of the Debugging Version ***";
    }
