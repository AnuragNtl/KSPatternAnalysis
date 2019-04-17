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
int counter;
KeyState(int);
KeyState() : state(false),counter(0){}
operator int()
{
	return counter;
}
};
KeyState :: KeyState(int counter) : counter(counter) {}
struct RecData
{
	int counter;
	KeyState *states;
	RecData() : states(new KeyState[KEYS_LENGTH]),counter(0) {}
	~RecData();
	bool& operator[](int);
	KeyState& stateAt(int index)
	{
		return states[index];
	}
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
	vector<vector<int> > getDataMatrix();
};
vector<vector<int> > Recorder :: getDataMatrix()
	{
		vector<vector<int> > r(duration);
		for(int i=0;i<duration;i++)
		{
			r[i]=vector<int>(KEYS_LENGTH);
			for(int k=0;k<KEYS_LENGTH;k++)
			r[i][k]=data[i].stateAt(k).counter;
		}
		return r;
	}

int Recorder :: getDuration()
{
return duration;
}
int Recorder :: getNumberOfKeys()
{
	return numberOfKeys;
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
cout <<"start\n";
while(time(NULL)-start<duration)
{
	cout <<"::" <<(int)(time(NULL)-start) <<"\n";
int key=getNextKey();
if(key!=-1 && i<duration)
{
data[i][key]=true;
data[i].stateAt(key).counter=numberOfKeys;
cout <<"State at " <<data[i].stateAt(key).counter <<"\n";
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
