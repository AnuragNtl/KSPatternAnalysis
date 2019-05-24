#ifndef FSIOL_H
#define FSIOL_H
#include"FSIO.h"

using namespace std;
class FSIOL : public FSIO
{
public:
	bool exists(string) const;
	void createDirectory(string) const;
};
#endif
