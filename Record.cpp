#include<iostream>
#include"LRecorder.h"
#include"CmdlineLabelAssigner.h"
#include"Extraction.h"
string getContents(string);
int main(int argc,char *argv[])
{
	try
	{
	    
LRecorder rec(10,"/dev/input/by-path/platform-i8042-serio-0-event-kbd");
rec.start();
RecData *data=rec.getData();
for(int i=0;i<10;i++)
{
	for(int k=0;k<128;k++)
		if(data[i][k]==1)
			cout <<k <<" ";
		cout <<"\n";
		}
vector<vector<bool> > data1=rec.getDataMatrix();
for(int i=0;i<data1.size();i++)
{
for(int k=0;k<KEYS_LENGTH;k++)
cout <<data1[i][k];
cout <<"\n";
}
cout <<rec.getNumberOfKeys() <<"\n";
CmdlineLabelAssigner ll1;
cout <<ll1.getLabel() <<"\n";
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
 if(!in.eof())
     data=data+"\n"+rd;
 }
 while(!in.eof());
 return data;
}
