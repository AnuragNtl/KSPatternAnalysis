#ifndef CMDLINE_LABEL_ASSIGNER
#define CMDLINE_LABEL_ASSIGNER
#include"LabelAssigner.h"
#include<iostream>
using namespace std;
class CmdlineLabelAssigner : public LabelAssigner
{
public:
	CmdlineLabelAssigner();
	string getLabel();
};
CmdlineLabelAssigner :: CmdlineLabelAssigner()
{

}
string CmdlineLabelAssigner :: getLabel()
{
string lbl;
cin >>lbl;
return lbl;
}
#endif
