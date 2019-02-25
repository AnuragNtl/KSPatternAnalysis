#include<iostream>
#include"LRecorder.h"
#include"CmdlineLabelAssigner.h"
class S1
{
public:
virtual void show(){cout <<"______\n";}    
};
class S2 : public S1
{
  public:
  void show(){cout <<"___:::::::____\n";}
};
int main(int argc,char *argv[])
{
    S2 s22;
    S1 &s2=s22;
    s2.show();
    return 0;
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
