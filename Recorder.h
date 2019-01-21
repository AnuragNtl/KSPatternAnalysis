#ifndef define
#define RECORDER_H

#include<ctime>
#include<string>
#include<cstdio>
#include<vector>

using namespace std;
#define KEYS_LENGTH 128

struct KeyState
{
bool state;
KeyState() : state(false){}
};
struct RecData
{
	KeyState *states;
	RecData() : states(new KeyState[KEYS_LENGTH]) {}
	~RecData();
	bool& operator[](int);
};
bool& RecData :: operator[](int index)
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
bool started;
int numberOfKeys;
	public:
	Recorder(int duration) : duration(duration),started(false),data(new RecData[duration]),numberOfKeys(0){}
	virtual int getNextKey()=0;
	void start();
	int getDuration();
	int getNumberOfKeys();
	RecData* getData()
	{
		return data;
	}
	~Recorder()
	{
		delete[] data;
	}
	vector<vector<bool> > getDataMatrix();
};
vector<vector<bool> > Recorder :: getDataMatrix()
	{
		vector<vector<bool> > r(duration);
		for(int i=0;i<duration;i++)
		{
			r[i]=vector<bool>(KEYS_LENGTH);
			for(int k=0;k<KEYS_LENGTH;k++)
			r[i][k]=data[i][k];
		}
		return r;
	}

int Recorder :: getDuration()
{
return duration;
}
void Recorder :: start()
{
	started=true;
time_t start,prevSec;
double timeDiff=0;
time(&start);
prevSec=start;
timeDiff=0;
int i=0;
while(time(NULL)-start<duration)
{
int key=getNextKey();
if(key!=-1 && i<duration)
{
data[i][key]=true;
numberOfKeys++;
}
timeDiff=(time(NULL)-prevSec);
if(timeDiff>1)
	prevSec=time(NULL);
i=(int)(time(NULL)-start);
cout <<(int)(time(NULL)-start) <<endl;
}
}
#endif
