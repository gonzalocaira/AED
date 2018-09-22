#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void readFile()
{
    ifstream file;
    file.open ("SPANISH.TXT");
    if (!file.is_open()) return;

    string word;
    while (file >> word)
    {
        cout<< word << '\n';
    }
}

int main () {
  //vector
  vector<vector<string> > myvector;
  //lectura
  string line;
  ifstream myfile ("SPANISH.TXT");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) ){
      vector<string> vector_word;
      while (myvector>>word){
          vector_word.push_back(word);
      }
      myvector.push_back(vector_word);
    }
    myfile.close();
  }
  else cout << "No se puedo abrir el archivo"<<endl;

  for (int i=0;i<myvector.size();i++){
    cout<<myvector[i][1]<<endl;
  }

  //vector
  /*string prueba;
  prueba="posdp ijd jkaskj askjdaksdj";
  cout<<prueba[0]<<endl;

    vector<string> v;
    istringstream buf(prueba);
    for(string word; buf >> word; ) {
      v.push_back(word);
    }
    for (int i=0; i<v.size();i++){
      cout<<v[i]<<endl;
    }
*/
  /*
  vector<vector<string> > myvector;
  for (int i=0; i<4;i++){
    vector<string> word;
    for(int j=0; j<4; j++){
      word.push_back ();
    }
    myvector.push_back(word);
  }

  cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
  for (int i=0;i<myvector.size();i++){
    for(int j=0; j<myvector.size();j++){
      cout<<myvector[i][j]<<endl;
    }
  }*/

  //readFile();

  return 0;
}
