#include<windows.h>
class WRecorder
{
private:
int i;
public:
WRecorder(){}
int getNextKey();
};
int WRecorder :: getNextKey()
{
int k=i;
for(short i=i;i!=k;i=(i<222?i+1:0))
if(GetASyncKeyState(i)==-32767)
return i;
}

