#ifndef FSIO_H
#define FSIO_H
#include<string>
using namespace std;
class FSIO
{
public:
virtual bool exists(string path) const=0;
virtual void createDirectory(string) const=0;
};
#include"FSIOL.h"
#include"FSIOW.h"
extern const FSIO* getDefaultFSIO();
#endif
