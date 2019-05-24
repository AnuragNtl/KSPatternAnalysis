#include"FSIOL.h"
#include<unistd.h>
#include<iostream>
#include<sys/stat.h>
#include<sys/types.h>

bool FSIOL :: exists(string path) const
{
	return access(path.c_str(),F_OK)!=-1;
}
void FSIOL :: createDirectory(string path) const
{
mkdir(path.c_str(),0);
}
