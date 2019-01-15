#inlcude<unistd.h>
#include<linux/input.h>
#include<stdio.h>
#include"Recorder.h"

class LRecorder : public Recorder
{
private:
	struct input_event ev;
	string dPath;
public:
	LRecorder(int,string);
	int getNextKey();
};
LRecorder :: LRecorder(int duration,string dPath) : Recorder(duration),
dPath(dPath)
{

}
int LRecorder :: getNextKey()
{

int fd;
fd=open(dPath.c_str(),O_RDONLY);
if(fd==-1)
	return;
struct input_event ev;
size_t n=read(fd,&ev,sizeof(ev));
if(n==(size_t)-1 || n!=sizeof(ev))
	return;
else
{
	if(ev.type==EV_KEY && (ev.value==1))
		return ev.code;
}
}
