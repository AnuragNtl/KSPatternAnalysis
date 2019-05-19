#include<iostream>
#include"LRecorder.h"
#include"CmdlineLabelAssigner.h"
#include<fstream>
#include"Extraction.h"
string getContents(string);
//#include"keyboard.h"
int main(int argc,char *argv[])
{
  char optString[]="o:bktsvd:";
  int duration=10;
  bool raw=false;
  string directory;
  bool typedCharacters=false,typedStrings=false,typeSpeed=false,typeKeyCodes=false;
  int opt=getopt(argc,argv,optString);
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
LRecorder rec(4,inputFile);
rec.start();
vector<vector<int> > data1=rec.getDataMatrix();
for(int i=0;i<data1.size();i++)
{
for(int k=0;k<KEYS_LENGTH;k++)
cout <<data1[i][k];
cout <<"\n";
}
cout <<"_______________\n";
cout <<rec.getNumberOfKeys() <<"\n";
SimpleExtraction extraction(data1);
cout <<extraction.getCharacterLength() <<"\n";
vector<string> typed=extraction.getTypedCharacters();
cout <<"_______Typed________\n";
for(int i=0;i<typed.size();i++)
cout <<typed[i] <<"\n";
//CmdlineLabelAssigner ll1;
//cout <<ll1.getLabel() <<"\n";
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
