#include<iostream>
#include"LRecorder.h"
//#include"PopupLabelAssigner.h"
#include<fstream>
#include <ctime>
#include"Extraction.h"
#include"FSIO.h"
#include"PopupManager.h"
#include "Capture.h"

string getContents(string);

void showMessage();
int main(int argc,char *argv[])
{
  char optString[]="o:bktsvd:anyil";
  int duration=10;
  bool raw=false;
  string directory=".";
  bool typedCharacters=false,typedStrings=false,typeSpeed=false,typeKeyCodes=false;
  int opt=getopt(argc,argv,optString);
  bool alphaCount = false, digitCount = false, alnumCount = false, symbolCount = false,
       actionKeysCount = false;
  const FSIO *fsio=getDefaultFSIO();
  if(argc <= 1) {
    showMessage();
    return 0;
  }
while(opt!=-1)
{
  cout <<(char)opt <<endl;
switch(opt)
{
  case 'o':
    directory=optarg;
    break;
  case 'b':raw=true;
           break;
  case 'k':typeKeyCodes=true;
           break;
  case 't':typedCharacters=true;
           break;
  case 's':typedStrings=true;
           break;
  case 'v':typeSpeed=true;
           break;
  case 'd':duration=stoi(string(optarg));
           break;
  case 'a':alphaCount = true;
  break;
  case 'n':digitCount = true;
  break; 
 case 'y':alnumCount = true;
  break;
  case 'i':
  symbolCount = true;
  break;
  case 'l':actionKeysCount = true;
  break;
  case '?':cout <<"Unknown option " <<(char)opt <<"\n";
           break;
}
opt=getopt(argc,argv,optString);
}
cout <<raw <<" " <<directory <<"\n";
cout <<duration <<"\n";
	try
	{
	    string inputFile=getContents("Recorder.conf");
	    cout <<inputFile <<"\n";
LRecorder rec(duration,inputFile);
cout << "Starting recording\n";
rec.start();
cout << "Getting label from popup\n";
string label = getLabelFromPopup();
cout << label << endl;
if(!fsio->exists(directory))
{
  fsio->createDirectory(directory);
}
time_t startTime;
time(&startTime);
string recordTime = to_string(startTime);
directory = directory + "/KSPatternAnalysis_" + recordTime;
fsio->createDirectory(directory);
if(raw)
{
  vector<vector<int> > rawMatrix=rec.getDataMatrix();
  ofstream rawFile(directory+"/RawMatrix.txt");
  for(vector<vector<int> > :: iterator it=rawMatrix.begin();it!=rawMatrix.end();it++)
  {
    for(vector<int> :: iterator it1=it->begin();it1!=it->end();it1++)
    {
      rawFile <<*it1;
    }
    rawFile <<endl;
  }
  rawFile.close();
}
vector<vector<int> > data1=rec.getDataMatrix();
SimpleExtraction extraction(data1);
if(typedCharacters)
{
  ofstream typedCharactersFile(directory+"/TypedCharacters.txt");
  vector<string> typedWords=extraction.getTypedCharacters();
  for(int i=0;i<typedWords.size();i++)
  {
     typedCharactersFile <<typedWords[i] <<endl;
  }
  typedCharactersFile.close();
}
if(typeSpeed)
{
  ofstream speedFile(directory+"/Speed.txt");
  speedFile <<extraction.getSpeed() <<endl;
  speedFile.close();
}
cout <<extraction.getCharacterLength() <<"\n";
vector<string> typed=extraction.getTypedCharacters();
cout <<"_______Typed________\n";
for(int i=0;i<typed.size();i++)
cout <<typed[i] <<"\n";
//CmdlineLabelAssigner ll1;
//cout <<ll1.getLabel() <<"\n";
if(typeKeyCodes) {
  ofstream keyCodesFile(directory + "/KeyCodes.txt");
  vector<vector<int> > keyCodes = extraction.getTypedKeyCodes();
  for(vector<vector<int> > :: iterator it = keyCodes.begin(); it != keyCodes.end(); it++) {
    for(vector<int> :: iterator it1 = it->begin(); it1 != it->end(); it1++)
      keyCodesFile << *it1;
    keyCodesFile << "\n";
  }
  keyCodesFile.close();
}
if(typedStrings) {
  ofstream typedStringsFile(directory + "/TypedStrings.txt");
  vector<string> typedStrings = extraction.getTypedCharacters();
  for(auto it = typedStrings.begin(); it != typedStrings.end(); it++) {
    typedStringsFile << *it << endl;
  }
  typedStringsFile.close();
}
if(alphaCount || digitCount || alnumCount || symbolCount || actionKeysCount) {
  ofstream countFile(directory + "/Count.txt");
  if(alphaCount)
    countFile << "AlphaCount = " << extraction.countAlphas() << endl;
  if(digitCount)
    countFile << "DigitCount = " << extraction.countDigits() << endl;
  if(alnumCount)
    countFile << "AlnumCount = " << extraction.countAlnums() << endl;
  if(symbolCount)
    countFile << "SymbolCount = " << extraction.countSymbols() << endl;
  if(actionKeysCount)
    countFile << "ActionKeysCount = " << extraction.countActionKeys() << endl;
  countFile.close();
}
}
catch(std::exception &e)
{
	cout <<e.what() <<"\n";
}
return 0;
}
string getContents(string file)
{
    string data="";
 string rd="";
 ifstream in(file);
do
 {
 getline(in,rd);
     data=data+rd+(!in.eof()?"\n":"");
 }
 while(!in.eof());
 return data;
}
void showMessage() {
  cout << "\tKS Pattern Recorder \n";
  cout << "Usage:\n";
  cout << "Record [OPTIONS]\n";
  cout << "OPTIONS:\n";
  cout << "-o DIRECTORY : Output Directory to save the recorded data\n";
  cout << "-b : Save Raw data matrix\n";
  cout << "-k : Save typed Key Codes in sequence\n";
  cout << "-t : Save typed Strings\n";
  cout << "-v : Save type speed\n";
  cout << "-d : Duration for recording\n";
  cout << "-a : Save Alphabet Count\n";
  cout << "-n : Save Digit Count\n";
  cout << "-y : Save Alphanumeric Count\n";
  cout << "-i : Save Symbol Count\n";
  cout << "-l : Save Action Keys Count\n";
  cout << "-a : Append to existing files\n";
}
