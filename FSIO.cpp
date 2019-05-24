#include"FSIO.h"
#ifdef WIN
const FSIO* getDefaultFSIO()
{
return NULL;
}
#else
const FSIO* getDefaultFSIO()
{
	return new FSIOL;
}
#endif