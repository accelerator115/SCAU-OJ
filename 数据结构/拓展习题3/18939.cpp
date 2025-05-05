#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string sentence;
    getline(cin, sentence);
    istringstream iss(sentence);
    string word, longest_word;
    int max_length = 0;
    while (iss >> word)
    {
        if (word.back() == '.')
        {
            word.pop_back();
        }
        if (word.length() > max_length)
        {
            max_length = word.length();
            longest_word = word;
        }
    }
    cout << longest_word << endl;
    return 0;
}
