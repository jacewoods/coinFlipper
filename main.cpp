#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    cout << "It's You vs. The Computer!" << endl;
    cout << "First to guess Three Correct Coin Flips is the Winner!" << endl;

    int p1 = 0;
    int c = 0;
    srand(time(nullptr));
    int headORtail;
    string playChoiceS;
    int playChoice;
    string compChoiceS;
    int compChoice;
    while(p1 < 3 && c < 3) {
        cout << "Current Score:" << endl << "You: " << p1 << endl << "CPU: " << c << endl;
        this_thread::sleep_for (chrono::seconds(1));
        cout << "Your Turn!" << endl;
        headORtail = rand()%2;
        while(playChoiceS != "Heads" && playChoiceS != "heads" && playChoiceS != "Tails" && playChoiceS != "tails") {
            cout << "Enter \"Heads\" or \"Tails\": ";
            cin >> playChoiceS;
        }
        if(playChoiceS == "Heads")
            playChoice = 0;
        else
            playChoice = 1;

        if (headORtail == playChoice) {
            cout << playChoiceS << " is correct! You earn One Point!" << endl;
            p1++;
            this_thread::sleep_for (chrono::seconds(1));
        }

        else {
            cout << playChoiceS << " is incorrect!" << endl;
            this_thread::sleep_for (chrono::seconds(1));
        }

        headORtail = rand()%2;
        compChoice = rand()%2;
        if(compChoice == 0)
            compChoiceS = "Heads";
        else
            compChoiceS = "Tails";
        cout << "CPU's Turn!" << endl;
        this_thread::sleep_for (chrono::seconds(1));
        cout << "CPU Chose " << compChoiceS << "!" << endl;
        this_thread::sleep_for (chrono::seconds(1));
        if(compChoice == headORtail) {
            cout << "CPU is correct! It is " << compChoiceS << "!" << " CPU earns One Point!" << endl;
            c++;
            this_thread::sleep_for (chrono::seconds(1));
        }
        else {
            cout << "CPU was Wrong!" << " It wasn't " << compChoiceS << "!" << endl;
            this_thread::sleep_for (chrono::seconds(1));
        }


        playChoiceS = "again";
    }
    cout << "Looks like someone reached THREE! Final score is: " << endl << "You: " << p1 << endl << "CPU: " << c << endl;
    this_thread::sleep_for (chrono::seconds(3));
    if(p1 == c)
        cout << "Wow, It's a draw! Thanks for playing!" << endl;
    else if(p1 > c)
        cout << "You defeated the Computer! Good job!" << endl;
    else
        cout << "The Computer defeated you! He will now take over the planet!" << endl;
    return 0;
}
