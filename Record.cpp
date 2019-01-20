#include<iostream>
#include"LRecorder.h"
int main()
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
return 0;
}
