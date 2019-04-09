#include<iostream>
#include<jni.h>
#include<unistd.h>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>

using namespace std;
#ifdef _WIN32
#define PATH_SEPERATOR ';'
#else
#define PATH_SEPERATOR ':'
#endif

string getLabelFromPopup()
{
	JavaVMOption options[1];
	JNIEnv *env;
	JavaVM *jvm;
	JavaVMInitArgs vm_args;
	long status;
	jclass cls;
	jmethodID mid;
	jstring p;
	options[0].optionString="-Djava.class.path=.:./json-rpc-1.0.jar";
	memset(&vm_args,0,sizeof(vm_args));
	vm_args.version=JNI_VERSION_1_8;
	vm_args.nOptions=1;
	vm_args.options=options;
	status=JNI_CreateJavaVM(&jvm,(void**)&env,&vm_args);
	if(status==JNI_OK)
		cout <<"Initialization Successful\n";
	if(status==JNI_ERR)
	{
		cout <<"Error\n";
		return 1;
	}
	cls=env->FindClass("Popup");
	if(cls==NULL)
	{
		cout <<"Class Not Found\n";
	}
	mid=env->GetStaticMethodID(cls,"getLabel","()Ljava/lang/String;");
	if(mid!=0)
	{
		p=(jstring)env->CallStaticObjectMethod(cls,mid);
		cout <<"Result " <<env->GetStringUTFChars(p,NULL) <<":\n";
		}
	else
		cout <<"Cant Call\n";
	jvm->DestroyJavaVM();
return env->GetStringUTFChars(p,NULL);
}
