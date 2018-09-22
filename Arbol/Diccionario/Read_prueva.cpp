#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

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
/*
  //vector
  vector<vector<string> > myvector;
  //lectura
  string line;
  ifstream myfile ("SPANISH.TXT");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) ){
      vector<string> vector_word;
      istringstream buf(line);
      int i=0;
      string word_second=" ";
      for (string word;buf>>word; i++){
        if (i==0) vector_word.push_back(word);
        word_second=word_second+word+" ";
      }
      vector_word.push_back(word_second);
      myvector.push_back(vector_word);
    }
    myfile.close();
  }
  else cout << "No se puedo abrir el archivo"<<endl;

  for (int i=0;i<myvector.size();i++){
    cout<<myvector[i][1]<<endl;
  }*/

/*
  string wordls=" ";
  string lol="as";
  for (int i=0;i<5;i++){
    wordls=wordls+lol+" ";
  }
  cout<<wordls<<endl;*/
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

  int iSecret;

    /* initialize random seed: */
    srand (time(NULL));
    for (int j=0;j<9;j++){
    int i;
    /* generate secret number between 1 and 10: */
    iSecret = rand() % 5000 ;
cout<<iSecret<<endl;
  i=rand()%5000+5000;
  cout<<i<<endl;}

  return 0;
}
