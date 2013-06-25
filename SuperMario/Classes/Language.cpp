#include "Language.h"
#include "iconv/iconv.h"
#include "CSVFile.h"

CLanguage* CLanguage::shareLanguage()
{
	static CLanguage* spLanguage = 0;
	if(spLanguage == 0)
	{
		spLanguage =  new CLanguage();
		spLanguage->Init();
	}
	return spLanguage;

}

int CLanguage::Convert( std::string & gbkStr, const char* toCode, const char* fromCode )
{

	iconv_t iconvH;
	iconvH = iconv_open(toCode,fromCode);
	if (iconvH == 0)
	{
		return -1;
	}

	const char* strChar = gbkStr.c_str();
	const char** pin = &strChar;
	size_t strLength = gbkStr.length();
	char* outbuf = (char*) malloc(strLength*4);
	char* pBuff = outbuf;

	memset( outbuf, 0, strLength*4);
	size_t outLength = strLength*4;
	if (-1 == iconv(iconvH, pin, &strLength, &outbuf, &outLength))
	{
		iconv_close(iconvH);
		return -1;
	}
	gbkStr = pBuff;
	iconv_close(iconvH);
	return 0;
}



const char * CLanguage::GetByKey( const char *key )
{
	map<string,string >::iterator itr = m_mapStr.find(key);
	if(itr == m_mapStr.end())
		return key;
	return itr->second.c_str();
}

bool CLanguage::Init()
{
	CSVFile csv;
	csv.Open(true,"language.txt");
	std::string strKey;
	std::string strValue;
	while (csv.CSVReadNextRow())
	{
		csv.CSVRead("key",strKey);
		csv.CSVRead("value",strValue);
		m_mapStr[strKey] = strValue;

	}
	csv.Close();
	return true;
}

