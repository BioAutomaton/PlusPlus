#include <iostream>
#include <windows.h>
#include <string>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main()
{
	char s1[50] = "jack";
	char s2[50] = "jill";
	char s3[50], * sptr;
	cout << strcpy_s(s3, s2) << endl;
}