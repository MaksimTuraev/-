#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

int main() {
    string name1, name2;
    cout << "Enter input filename (name1): ";
    cin >> name1;
    cout << "Enter output filename (name2): ";
    cin >> name2;

    ifstream inFile(name1);
    if (!inFile) {
        cerr << "Error opening input file: " << name1 << endl;
        return 1;
    }

    vector<string> wordsFromFile;
    copy(istream_iterator<string>(inFile), 
         istream_iterator<string>(), 
         back_inserter(wordsFromFile));
    inFile.close();

    cout << "Enter words to process (end with Ctrl+D/Ctrl+Z): ";
    vector<string> inputWords;
    copy(istream_iterator<string>(cin), 
         istream_iterator<string>(), 
         back_inserter(inputWords));

    ofstream outFile(name2);
    if (!outFile) {
        cerr << "Error opening output file: " << name2 << endl;
        return 1;
    }

    transform(inputWords.begin(), inputWords.end(),
              wordsFromFile.begin(),
              ostream_iterator<string>(outFile, "\n"),
              [](const string& inputWord, const string& fileWord) {
                  return inputWord + "-" + fileWord;
              });

    outFile.close();
    cout << "Processing complete. Results written to " << name2 << endl;

    return 0;
}
