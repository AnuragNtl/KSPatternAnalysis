#ifndef RECORDER_H
#define RECORDER_H
struct RecData
{
	int keyCode;
	bool pressed;
	long instant;
	RecData(int kCode,bool p,long instant) : keyCode(kCode),pressed(p),instant(instant) {}
};
class Recorder
{
	public:
	Recorder()
};
#endif
