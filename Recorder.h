#ifndef define
#define RECORDER_H

#include<ctime>
#include<string>
#include<unistd.h>
#include<cstdio>
#include<fcntl.h>

using namespace std;

struct KeyState
{
unsigned int state;
KeyState() : state(0){}
};
struct RecData
{
	KeyState *states;
	RecData() : states(new KeyState[128]) {}
	~RecData();
	unsigned int& operator[](int);
};
unsigned int& RecData :: operator[](int index)
{
	return states[index].state;
}
RecData :: ~RecData()
{
	delete[] states;
}
class Recorder
{
protected:
RecData *data;
int duration;
	public:
	Recorder(int duration) : duration(duration),data(new RecData[duration]){}
	virtual int getNextKey()=0;
	void start();
	int getDuration();
	RecData* getData()
	{
		return data;
	}
	~Recorder()
	{
		delete[] data;
	}
};
int Recorder :: getDuration()
{
return duration;
}
void Recorder :: start()
{
time_t start,prevSec;
double timeDiff=0;
time(&start);
prevSec=start;
timeDiff=0;
while(time(NULL)-start<duration)
{
int key=getNextKey();
if(key!=-1)
data[(int)timeDiff][key]=1;
timeDiff=(time(NULL)-prevSec);
if(timeDiff>1)
	prevSec=time(NULL);
cout <<(time(NULL)-start) <<endl;
}
}
#endif
