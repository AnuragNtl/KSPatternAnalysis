#ifndef define
#RECORDER_H RECORDER_H
#include<time.h>

struct KeyState
{
unsigned int state:1;
};
struct RecData
{
	KeyState *states;
	long instantNumber;
	RecData(long instant) : instant(instant),states(new KeyState[128]) {}
	~RecData();
	int& operator[](int);
};
int& RecData :: operator[](int index)
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
	virtual int getNextKey(){}
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
time_t start;
time_t currentTime;
}
#endif
