
/**
* Simple quiz
*/

#include<iostream>
#include<iomanip>






class quiz {

private:

    /**
    * All the questions of the quiz
    */
    char* quest[7] = {
      " Who is Andre Moroa?",
      " What is the light?",
      " Who is Stendal?",
      " What is the sound?",
      " What is the Otonogenesis?",
      " Who writes 'The dead of Vergilii'?",
      " Choose the right formula of the ammonya"
    };


    /**
    * All the answers
    * every question has 3 options and 1 correct answer
    */
    char* ans[7][3] = {
      {"A. French writer","B. English compositor","C. German imperator"},
      {"A. piece","B. wave","C. act like both"},
      {"A. English pianoman","B. Italian moviemaker","C. French writer"},
      {"A. wave","B. piece","C. unknown"},
      {"A. Repeating of the Filogenesis","B. Borning procces","C. Reborning"},
      {"A. Herman Broch","B. David Mayer","C. Mark Antony"},
      {"A. H2O","B. NH3","C. OH2"}
    };


    /**
    * Correct answers
    */
    char keys[7] = { 'A','C','C','A','A','A','B' };



    /**
    * Scores
    * every correct answer brings 1 score
    * max scores 7
    */
    int scores = 0;



    /**
    * Assesment
    * 0 scores -- 2
    * 1 scores -- 2
    * 2 scroes -- 3
    * 3 scores -- 3
    * 4 scores -- 4
    * 5 scores -- 4
    * 6 scores -- 5
    * 7 scores -- 6
    */
    int assesment = 0;



public:

    /**
    * Startup menu
    */
    inline void start_quiz();



    /**
    * Make the quiz
    */
    void show_quest_and_ans();



    /**
    * Choose assesment and show it with the points
    */
    void show_assesment();



    /**
    * Exit
    */
    static inline void _EXIT_();



};







//definitions

void quiz::show_quest_and_ans() {

    char choise;
    int quest_quantity = sizeof(quest) / sizeof(quest[0]);

    std::cout << " Have a nice play!\n\n\n\n";
    std::cout << "=========================================================\n";
    std::cout << " The quiz has 7 questions\n";
    std::cout << " Every question has 3 options and 1 rigth option!\n Every rigth option brings 1 point.\n";
    std::cout << " Type the letter of the correct answer.\n\n\n";
    std::cout << " Assessment scale\n";
    std::cout << "   0 points - 2\n   1 point - 2\n   2 points - 3\n   3 points - 3\n   4 points - 4\n   5 points - 4\n   6 points - 5\n   7 points - 6\n";
    std::cout << "=========================================================\n\n\n\n";

    for (int i = 0; i < quest_quantity; i++) {
        std::cout << "--------------------------------------------------\n";
        std::cout << " Question " << i + 1 << "\n\n";
        std::cout << " " << quest[i] << std::endl << std::endl;

        for (int j = 0; j < sizeof(ans[i]) / sizeof(ans[i][0]); j++) {
            std::cout << "    " << ans[i][j] << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Type the letter of the answer > ";
        std::cin >> choise;
        choise = toupper(choise);

        if (choise == keys[i]) {
            std::cout << "\n\nCorrect answer!\n\n";
            scores++;
        }
        else {
            std::cout << "\n\nWrong answer!\nCorrect answer : " << keys[i] << "\n\n";
        }

    }

    show_assesment();

}



void quiz::show_assesment() {

    switch (scores) {
    case 0:
        assesment = 2;
        break;
    case 1:
        assesment = 2;
        break;
    case 2:
        assesment = 3;
        break;
    case 3:
        assesment = 3;
        break;
    case 4:
        assesment = 3;
        break;
    case 5:
        assesment = 3;
        break;
    case 6:
        assesment = 5;
        break;
    case 7:
        assesment = 6;
        break;
    }

    std::cout << "\n\n";
    std::cout << "================================================================\n";
    std::cout << " Scores : " << scores << "\n Assesment : " << assesment << "\n";

    std::string msg;
    switch (assesment) {
    case 2:
        msg = " Very bad, like i expect from you!";
        std::cout << msg << std::endl << std::endl;
        break;
    case 3:
        msg = " You hit the middle, but you luck brings you here!";
        std::cout << msg << std::endl;
        break;
    case 4:
        msg = " Good, but you can more!";
        std::cout << msg << std::endl;
        break;
    case 5:
        msg = " Very good, but not excellent! Thing about that!";
        std::cout << msg << std::endl;
        break;
    case 6:
        msg = " Excellent! I know you know!";
        std::cout << msg << std::endl;
        break;
    }

    std::cout << "================================================================\n\n\n\n";

}



inline void quiz::_EXIT_() { std::cout << "\n\n Goodbye!\n\n"; }




inline void quiz::start_quiz() {

    int opt;

    std::cout << std::setw(70) << std::setfill('-') << " Quiz of the day ------------------------\n\n\n";
    std::cout << " Choose option\n\n";
    std::cout << "  1. Start new quiz\n  2. exit\n\n\n";

    std::cin >> opt;

    std::cout << std::endl << std::endl;

    switch (opt) {
    case 1:
        show_quest_and_ans();
        break;
    case 2:
        _EXIT_();
        break;
    }

}







/**
* Main
*/

int main() {

    quiz quiz, * game = &quiz;
    game->start_quiz();

    return 0;
}
