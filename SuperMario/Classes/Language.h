#ifndef __LANGUAGE_H__
#define __LANGUAGE_H__
#include <string>
#include <map>
using namespace  std;

class CLanguage
{
public:
	CLanguage(){};
	~CLanguage(){};
	bool Init();

	static CLanguage* shareLanguage();
	static int Convert(string & gbkStr, const char* toCode, const char* fromCode);
	const char * GetByKey(const char *key);
private:
	map<string,string > m_mapStr;
};
#endif