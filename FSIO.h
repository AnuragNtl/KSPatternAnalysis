#ifndef FSIO_H
#define FSIO_H
#ifdef WIN
class FSIO
{
public:
virtual bool exists(string path)=0;
virtual void createDirectory(string)=0;
};
#endif
#endif
