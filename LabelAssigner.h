#ifndef LABEL_ASSIGNER_H
#define LABEL_ASSIGNER_H
#include<string>
using namespace std;
class LabelAssigner
{
public:
	LabelAssigner();
	virtual string getLabel()=0;
};
LabelAssigner :: LabelAssigner()
{
	
}
#endif
