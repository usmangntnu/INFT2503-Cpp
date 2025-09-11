#include <iostream>
#include <string>
using namespace std;

int main() {

  // a) Les inn tre ord
  string word1, word2, word3;

  cout << "Please enter word1: ";
  cin >> word1;

  cout << "And now enter word2: ";
  cin >> word2;

  cout << "Lastly, enter word3: ";
  cin >> word3;

  // b) Lag en setning
  string sentence = word1 + " " + word2 + " " + word3 + ".";
  cout << "The sentence is: " << sentence << endl;

  // c) Skriv ut lengder
  cout << "Length of word1: " << word1.length() << endl;
  cout << "Length of word2: " << word2.length() << endl;
  cout << "Length of word3: " << word3.length() << endl;
  cout << "Length of sentence: " << sentence.length() << endl;

  // d) Lag en kopi
  string sentence2 = sentence;
  cout << "Copy of sentence: " << sentence2 << endl;

  // e) Bytt ut tegn nr 10–12 i sentence2
  size_t index1 = 10;
  size_t index2 = 12;

  if (index2 >= sentence2.length()) {
    cout << "Index out of bounds." << endl;
  } else {
    for (size_t i = index1; i <= index2; i++) {
      sentence2[i] = 'x';
    }
  }

  cout << "Original sentence: " << sentence << endl;
  cout << "Modified sentence2: " << sentence2 << endl;

  // f) Lagre de fem første tegnene
  string sentence_start;
  if (sentence.length() >= 5) {
    sentence_start = sentence.substr(0, 5);
    cout << "Sentence: " << sentence << endl;
    cout << "Sentence start: " << sentence_start << endl;
  } else {
    cout << "Sentence too short for extracting 5 characters." << endl;
  }

  // g) Finn ut om sentence inneholder "hallo"
  if (sentence.find("hallo") != string::npos) {
    cout << "\"hallo\" was found in the sentence." << endl;
  } else {
    cout << "\"hallo\" was NOT found in the sentence." << endl;
  }

  // h) Finn alle forekomster av "er"
  size_t pos = sentence.find("er");
  while (pos != string::npos) {
    cout << "\"er\" found at position: " << pos << endl;
    pos = sentence.find("er", pos + 1);
  }

  return 0;
}
