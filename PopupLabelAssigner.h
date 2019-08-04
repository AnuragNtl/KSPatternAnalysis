#ifndef POPUP_LABEL_ASSIGNER_H
#define POPUP_LABEL_ASSIGNER_H
#include"LabelAssigner.h"
#include<unistd.h>
#include"PopupManager.h"
#include<string>

using namespace std;

class PopupLabelAssigner : public LabelAssigner
{
public:
string getLabel();
};
string PopupLabelAssigner :: getLabel()
{
return getLabelFromPopup();
}
#endif
