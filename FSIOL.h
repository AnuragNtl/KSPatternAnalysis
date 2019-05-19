#ifndef FSIOL_H
#define FSIOL_H
#include<unistd.h>
#include<iostream>
#include<sys/stat.h>
#include<sys/types.h>
#include"FSIO.h"

using namespace std;
class FSIOL : public FSIO
{
public:
	bool exists(string);
	void createDirectory(string);
};
bool FSIOL :: exists(string path)
{

}
void FSIOL :: createDirectory(string path)
{
mkdir(path.c_str());
}
#endif
