// ============================================================
//  AI Roast Generator
//  A beginner-friendly C++ console program
//  Uses random selection to generate unique roast messages
// ============================================================

#include <iostream>   // For cin and cout
#include <vector>     // For storing roast templates
#include <string>     // For string operations
#include <cstdlib>    // For rand() and srand()
#include <ctime>      // For time() — used to seed the random generator

using namespace std;

// ---- Function: Replace placeholder {name} with the actual name ----
string applyRoast(string roastTemplate, const string& name) {
    string placeholder = "{name}";
    size_t pos = roastTemplate.find(placeholder); // Find where {name} is

    // BUG FIX: Check if placeholder actually exists before replacing
    // Without this check, the program would crash on templates missing {name}
    if (pos != string::npos) {
        roastTemplate.replace(pos, placeholder.length(), name); // Replace it
    }
    return roastTemplate;
}

int main() {

    // Seed the random number generator with current time
    // This ensures a different roast is picked each time the program runs
    srand(static_cast<unsigned int>(time(0)));

    // ---- Store all roast templates in a vector ----
    vector<string> roasts = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would already have a gold medal.",
        "{name}'s debugging style is basically staring at the screen until the bug gets embarrassed and leaves.",
        "{name}'s code runs so slowly that even dial-up internet feels fast.",
        "If laziness had a brand ambassador, it would be {name}.",
        "{name} doesn't debug code — they negotiate with bugs.",
        "Scientists studied {name}'s commit history and confirmed it's the leading cause of merge conflicts.",
        "{name} once tried to Google their own name and got zero results — even the internet gave up.",
        "The only thing {name} ships on time is excuses.",
        "{name}'s code is so tangled, even spaghetti filed a restraining order.",
        "They say AI will take everyone's jobs. {name}'s job is already safe — no AI would want it.",
        "{name} put 'fast learner' on their resume. The loading bar is still going."
    };

    string userName;

    cout << "========================================" << endl;
    cout << "        Welcome to the AI Roaster!      " << endl;
    cout << "========================================" << endl;

    // ---- BUG FIX: Handle empty name input ----
    // Original bug: if user pressed Enter without typing, the program
    // would roast with a blank name like " writes code so slow..."
    // Fix: Keep asking until a valid name is entered
    while (true) {
        cout << "\nEnter your name to get roasted: ";
        getline(cin, userName); // getline handles names with spaces

        if (!userName.empty()) {
            break; // Valid name entered, exit loop
        } else {
            cout << "[Error] Name cannot be empty. Please try again!" << endl;
        }
    }

    // ---- Randomly select a roast from the vector ----
    int randomIndex = rand() % roasts.size(); // Pick a random index

    // Apply the user's name to the selected template
    string finalRoast = applyRoast(roasts[randomIndex], userName);

    // ---- Display the roast ----
    cout << "\n----------------------------------------" << endl;
    cout << "ROAST OF THE DAY:" << endl;
    cout << finalRoast << endl;
    cout << "----------------------------------------" << endl;
    cout << "\n(Run the program again for a different roast!)" << endl;

    return 0;
}