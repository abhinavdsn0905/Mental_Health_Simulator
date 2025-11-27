#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

class User {
private:
    string name;
    vector<string> moodHistory;

public:
    User(const string& userName) : name(userName) {}

    void addMood(const string& mood) {
        moodHistory.push_back(mood);
    }

    vector<string> getMoodHistory() const {
        return moodHistory;
    }

    string getName() const {
        return name;
    }
};

class QuoteProvider {
public:
    static string getRandomQuote() {
        vector<string> quotes = {
            "You are stronger than you think.",
            "Every day is a new beginning.",
            "Your potential is limitless.",
            "Breathe. You've got this.",
            "Small steps lead to big changes."
        };

        srand(static_cast<unsigned int>(time(nullptr)));
        int index = rand() % quotes.size();
        return quotes[index];
    }
};

class CalmingExerciseProvider {
public:
    static string getExerciseForMood(const string& mood) {
        map<string, string> exercises = {
            {"happy", "Keep smiling and share your positivity with someone today!"},
            {"sad", "Take deep breaths for 1 minute and write down 3 things you're grateful for."},
            {"stressed", "Close your eyes, inhale for 4 seconds, hold for 4 seconds, exhale for 4 seconds."},
            {"angry", "Go for a short walk and focus on your surroundings."},
            {"neutral", "Listen to calming music for 5 minutes."}
        };

        string moodLower = mood;
        transform(moodLower.begin(), moodLower.end(), moodLower.begin(), ::tolower);

        if (exercises.count(moodLower)) {
            return exercises[moodLower];
        }
        return "Take a moment to relax and breathe.";
    }
};

class MoodTracker {
public:
    static string askMood() {
        string mood;
        cout << "How are you feeling today? (happy/sad/stressed/angry/neutral): ";
        getline(cin, mood);
        return mood;
    }
};

class Assistant {
private:
    User user;

public:
    Assistant(const string& name) : user(name) {}

    void startSession() {
        string mood = MoodTracker::askMood();
        user.addMood(mood);

        cout << "\nMotivational Quote: " << QuoteProvider::getRandomQuote() << "\n";
        cout << "Calming Exercise: " << CalmingExerciseProvider::getExerciseForMood(mood) << "\n";
    }
};

int main() {
    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    Assistant assistant(name);

    char choice;
    cout << "Do you want to start a session? (y/n): ";
    cin >> choice;
    cin.ignore(); 

    if (choice == 'y' || choice == 'Y') {
        assistant.startSession();
    } else {
        cout << "Okay, take care!\n";
    }

    return 0;
}

