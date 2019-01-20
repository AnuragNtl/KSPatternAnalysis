#ifndef LRECORDER_H
#define LRECORDER_H
#include<unistd.h>
#include<linux/input.h>
#include<stdio.h>
#include"Recorder.h"
#include<string>

using namespace std;

class LRecorder : public Recorder
{
private:
	struct input_event ev;
	string dPath;
	int fd;
public:
	LRecorder(int,string);
	int getNextKey();
};
LRecorder :: LRecorder(int duration,string dPath) : Recorder(duration),
dPath(dPath)
{
fd=open(dPath.c_str(),O_RDONLY);
}
int LRecorder :: getNextKey()
{
if(fd==-1)
	return -1;
struct input_event ev;
size_t n=read(fd,&ev,sizeof(ev));
if(n==(size_t)-1 || n!=sizeof(ev))
	return -1;
else
{
	if(ev.type==EV_KEY && (ev.value==1))
		return ev.code;
	else
		return -1;
}
}
#endif
