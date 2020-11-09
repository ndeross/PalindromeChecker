

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool CheckPalin(string& phrase, int s, int e);
void MessagePrint(bool isPalin, string phrase);
void BrokenFile(string phrase);

int main() {
  string phrase;
  bool isPalin;
  string inFileName;

  ifstream inFile;

  cout << "Enter the file name => ";

  getline(cin, inFileName);

  cout << endl;

  inFile.open(inFileName.c_str());

  if (!inFile) {
    BrokenFile(inFileName);
    return 0;
  }

  else

  {
    getline(inFile, phrase);
  }

  while (inFile) {
	  
      isPalin = CheckPalin(phrase, 0, phrase.length() - 1);

      MessagePrint(isPalin, phrase);

      getline(inFile, phrase);
  }

  return 0;
}




bool CheckPalin(string& phrase, int s, int e)

{
  

  if (s >= e) {
    return true;
  }
  if (phrase[s] != phrase[e]) {
    return false;
  }
  return CheckPalin(phrase, ++s, --e);
}

void MessagePrint(bool isPalin, string phrase)

{
  if (isPalin == true) {
    cout << "\"" << phrase << "\"" << " YES!" << endl;
  }

  else {
   cout << "\"" << phrase << "\"" <<  " no." << endl;
  }

  return;
}

void BrokenFile(string inFileName)

{
  cout << "The file " << inFileName << " does not exist." << endl;
  return;
}
