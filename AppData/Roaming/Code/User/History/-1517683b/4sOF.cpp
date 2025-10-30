#include <iostream> // for input and output
#include <sstream> // for stringstream - breaks sentences into words
#include <vector> // for std::vector
#include <string> // for std::string

using namespace std;

int main() {
    string sentence; // variable to hold input sentence
    
    // prompt user for sentence
    cout << "Enter a sentence: ";
    getline(cin, sentence); // read the full sentence including spaces
    
    vector<string> words; // vector to store all words from sentence
    string word; // temporary string to hold each word
    
    // use stringstream to split sentence into words - add individual words to vector later
    stringstream ss(sentence);
    while (ss >> word) { // extract word by word from the sentence
        words.push_back(word); // add each word to vector
    }
    
    // variables to tracking longest word
    string longestWord = "";
    int maxLength = 0;
    
    // loop through all words in the vector
    for (int i = 0; i < words.size(); i++) {
        if (words[i].length() > maxLength) { // check if current word is longer
            longestWord = words[i]; // update longest word
            maxLength = words[i].length(); // update maximum length
        }
    }
    
    // display the results
    cout << "Total number of words: " << words.size() << endl;
    cout << "Longest word: " << longestWord << endl;
    cout << "Length of longest word: " << maxLength << endl;

    return 0; // end of program, successful completim
}
