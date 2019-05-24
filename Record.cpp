#include<iostream>
#include"LRecorder.h"
#include"CmdlineLabelAssigner.h"
#include<fstream>
#include"Extraction.h"
string getContents(string);
#include"FSIO.h"
//#include"keyboard.h"
int main(int argc,char *argv[])
{
  char optString[]="o:bktsvd:";
  int duration=10;
  bool raw=false;
  string directory=".";
  bool typedCharacters=false,typedStrings=false,typeSpeed=false,typeKeyCodes=false;
  int opt=getopt(argc,argv,optString);
  const FSIO *fsio=getDefaultFSIO();
while(opt!=-1)
{
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
rec.start();
if(!fsio->exists(directory))
{
  fsio->createDirectory(directory);
}
if(raw)
{
  vector<vector<int> > rawMatrix=rec.getDataMatrix();
  ofstream rawFile(directory+"/RawMatrix.txt");
  for(vector<vector<int> > :: iterator it=rawMatrix.begin();it!=rawMatrix.end();it++)
  {
    for(vector<int> :: iterator it1=it->begin();it1!=it->end();it++)
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
if(typeKeyCodes)
{
  
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
