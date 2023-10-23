#include <iostream>
#include <string>

using namespace std;

int main() {

  cout << "Du skal skrive inn 3 ord.\n";

  string word1;
  cout << "Ord 1:\n";
  cin >> word1;

  string word2;
  cout << "Ord 2:\n";
  cin >> word2;

  string word3;
  cout << "Ord 3:\n";
  cin >> word3;

  string sentence = word1 + " " + word2 + " " + word3 + ".";

  cout << sentence << endl;

  cout << word1.length() << endl;
  cout << word2.length() << endl;
  cout << word3.length() << endl;
  cout << sentence.length() << endl;

  string sentence2 = sentence;

  if (sentence2.length() >= 12) {
    // sentence2[9] = sentence2[10] = sentence2[11] = 'X'; // Manuell fremgangsmåte
    sentence2.replace(9, 3, "XXX"); // Med string::replace
  }

  cout << sentence << endl;
  cout << sentence2 << endl;

  string sentence_start;
  if (sentence.length() >= 5) {
    sentence_start = sentence.substr(0, 5);
    cout << sentence << endl;
    cout << sentence_start << endl;
  }

  cout << "sentence inneholder ";
  if (sentence.find("hallo") == string::npos) {
    cout << "ikke ";
  }
  cout << "ordet 'hallo'" << endl;

  int counter = 0;
  for (size_t i = 1; i < sentence.length(); i++) {
    if (sentence[i - 1] == 'e' && sentence[i] == 'r') {
      counter++;
    }
  }
  cout << "Antall forekomster av 'er': " << counter << endl;
}
