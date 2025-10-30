#include <cctype>
bool isValidName(const string &name) {
    for (char c : name)
        if (!isalpha(c) && c != ' ')
            return false;
    return true;
}