// ============================================================
//  Homework Excuse Generator
//  A fun C++ program for students who... forgot their homework.
// ============================================================

// These lines bring in the "tools" we need:
#include <iostream>   // For printing to the screen and reading input
#include <vector>     // For using a list (vector) of excuses
#include <string>     // For working with text (strings)
#include <cstdlib>    // For rand() and srand() – our random number helpers
#include <ctime>      // For time() – used to seed the random number generator

int main() {

    // ----------------------------------------------------------
    // STEP 1: Seed the random number generator
    // ----------------------------------------------------------
    // srand() sets the "starting point" for random numbers.
    // Using time(0) means we get a different seed every second,
    // so we get a different excuse each time the program runs!
    srand(static_cast<unsigned int>(time(0)));


    // ----------------------------------------------------------
    // STEP 2: Store our excuse templates in a vector
    // ----------------------------------------------------------
    // A vector is like a list that can hold many items.
    // Each excuse has {name} as a placeholder — we'll replace it
    // with the student's actual name later.

    std::vector<std::string> excuses = {
        "Dear Teacher, {name} tried to submit the homework, but their dog "
        "learned to use the printer and printed 347 pages of his own portrait instead.",

        "Please excuse {name} — a rogue Wi-Fi signal from a passing pizza delivery "
        "drone corrupted the homework file and replaced it with a calzone recipe.",

        "Unfortunately, {name}'s homework was eaten. Not by a dog — by the "
        "Roomba, which has apparently developed a taste for knowledge.",

        "{name} was 80% done with the homework when the power went out. "
        "When it came back, the laptop had forgotten everything — just like a goldfish.",

        "Last night, {name}'s cat sat on the keyboard and submitted the homework "
        "to a NASA research portal. We're awaiting their peer review.",

        "{name} did complete the homework, but accidentally laminated it "
        "instead of scanning it. It is now waterproof but unreadable.",

        "A very unusual solar flare last night specifically targeted {name}'s "
        "desk and magnetised all their pens. Writing was physically impossible.",

        "{name}'s smart fridge gained sentience and held the homework hostage "
        "in exchange for more yogurt. Negotiations are still ongoing.",

        "Regrettably, {name} spilled an entire mug of hot chocolate on the homework. "
        "It now smells amazing but the ink has fully dissolved into the cocoa.",

        "{name} was about to finish the last question when a pigeon flew in through "
        "the window, grabbed the paper, and flew toward the horizon with great purpose.",

        "Due to a rare glitch, {name}'s phone autocorrected all homework answers "
        "to song lyrics. The assignment now reads like a One Direction album.",

        "{name} was fully prepared, but then the neighbour's Bluetooth speaker "
        "connected to their laptop uninvited and played ABBA for six hours straight."
    };

    // ----------------------------------------------------------
    // STEP 3: Count how many excuses we have
    // ----------------------------------------------------------
    // excuses.size() returns the number of items in our vector.
    // We'll use this to make sure rand() picks a valid index.
    int totalExcuses = static_cast<int>(excuses.size());


    // ----------------------------------------------------------
    // STEP 4: Ask the user for their name (with validation)
    // ----------------------------------------------------------
    // We use a loop so that if the user enters nothing,
    // we keep asking until they give us an actual name.

    std::string studentName;

    std::cout << "\n";
    std::cout << "  ==========================================\n";
    std::cout << "    HOMEWORK EXCUSE GENERATOR 3000 (v1.0)  \n";
    std::cout << "  ==========================================\n";
    std::cout << "\n";

    // This loop runs forever until we break out of it
    while (true) {
        std::cout << "  Enter your name, brave student: ";

        // getline reads the full line including spaces
        std::getline(std::cin, studentName);

        // Check if the name is empty (user just pressed Enter)
        if (studentName.empty()) {
            // Tell them what went wrong and try again
            std::cout << "\n  [ERROR] Name cannot be empty!\n";
            std::cout << "  Your teacher won't believe 'Unnamed Student' either.\n\n";
        } else {
            // Name is valid — exit the loop
            break;
        }
    }


    // ----------------------------------------------------------
    // STEP 5: Randomly pick one excuse from the vector
    // ----------------------------------------------------------
    // rand() generates a big random number.
    // Using % totalExcuses ensures the result is between 0 and
    // (totalExcuses - 1), which are valid list positions (indices).

    int randomIndex = rand() % totalExcuses;

    // Grab the chosen excuse from the vector
    std::string chosenExcuse = excuses[randomIndex];


    // ----------------------------------------------------------
    // STEP 6: Replace {name} with the actual student name
    // ----------------------------------------------------------
    // string::find() searches for a piece of text inside a string.
    // string::replace() swaps it out with something else.

    std::string placeholder = "{name}";  // What we're looking for

    // find() returns the position (index) where {name} starts.
    // If it can't find it, it returns std::string::npos (a special "not found" value).
    std::string::size_type position = chosenExcuse.find(placeholder);

    // Keep replacing as long as {name} is still found in the string
    while (position != std::string::npos) {
        // Replace the placeholder with the real student name
        chosenExcuse.replace(position, placeholder.length(), studentName);

        // Search again from where we left off (in case {name} appears twice)
        position = chosenExcuse.find(placeholder, position + studentName.length());
    }


    // ----------------------------------------------------------
    // STEP 7: Display the final excuse
    // ----------------------------------------------------------
    std::cout << "\n";
    std::cout << "  ------------------------------------------\n";
    std::cout << "   YOUR OFFICIAL EXCUSE:\n";
    std::cout << "  ------------------------------------------\n";
    std::cout << "\n";

    // Print the excuse, wrapping text manually for readability
    std::cout << "  " << chosenExcuse << "\n";

    std::cout << "\n";
    std::cout << "  ------------------------------------------\n";
    std::cout << "   Good luck, " << studentName << ". You'll need it.\n";
    std::cout << "  ==========================================\n";
    std::cout << "\n";

    // Returning 0 means the program finished successfully
    return 0;
}