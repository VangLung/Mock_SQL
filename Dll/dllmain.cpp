// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "application_Wrapper.h"
#include <string>
#include "DataBase.h"


using namespace std;


extern string Radi(DataBase* d, string query);

JNIEXPORT jstring JNICALL Java_application_Wrapper_exec (JNIEnv* env, jobject, jstring jupit)
{
	string upit = env->GetStringUTFChars(jupit, nullptr);
	string path = "C:\\Users\\Mateja\\Desktop\\ispis.txt";

	DataBase* d= DataBase::readFile(path);
	jstring s= env->NewStringUTF(Radi(d, upit).c_str());
	d->writeFile(path);
	return s;

	
}