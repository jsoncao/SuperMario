#include "CSVParse.h"

using namespace cocos2d;


CSVParse::~CSVParse()
{
    for (int i=0; i<data.size(); i++) {
        data[i].clear();
    }
    data.clear();
}

// split: split line into fields
void CSVParse::split(vector<string>& field,string line)
{
    string fld;
    int i, j;
    
    if (line.length() == 0)
        return ;
    i = 0;
    
    do {
        if (i < line.length() && line[i] == '"')
            j = advquoted(line, fld, ++i);    // skip quote
        else
            j = advplain(line, fld, i);

        field.push_back(fld);
        i = j + 1;
    } while (j < line.length());
    
}

// advquoted: quoted field; return index of next separator
int CSVParse::advquoted(const string& s, string& fld, int i)
{
    int j;
    
    fld = "";
    for (j = i; j < s.length(); j++)
    {
        if (s[j] == '"' && s[++j] != '"')
        {
            int k = s.find_first_of(fieldsep, j);
            if (k > s.length())    // no separator found
                k = s.length();
            for (k -= j; k-- > 0; )
                fld += s[j++];
            break;
        }
        fld += s[j];
    }
    return j;
}

// advplain: unquoted field; return index of next separator
int CSVParse::advplain(const string& s, string& fld, int i)
{
    int j;
    
    j = s.find_first_of(fieldsep, i); // look for separator
    if (j > s.length())               // none found
        j = s.length();
    fld = string(s, i, j-i);
    return j;
}


// getfield: return n-th field
const char* CSVParse::getData(int rows,int cols)
{
    if (rows<0||rows>=data.size()||cols<0||cols>=data[rows].size()) {
        return "";
    }
    
    return data[rows][cols].c_str();
}

int  CSVParse::findColsData(int cols,const char* value)
{
    for (int i=0; i<data.size(); i++) {
        if (strcmp(getData(i, cols), value)==0 )
        {
            return i;
        }
    }
    return -1;
}
//用于兼容windows下的换行符\r\n
//原因是在windows下换行符为\r\n，而在unix下则为\n
//进行封装,否则读取的每行读取的最后一个数据默认会有个额外的\r
bool getline(std::ifstream &is,std::string &str){
	bool b = std::getline(is,str);
	std::string::size_type p = str.find_last_of('\r');
	if(p != std::string::npos) str.erase(p);
	return b;
}

//读取方式: 逐行读取, 将行读入字符串, 行之间用回车换行区分
//If you want to avoid reading into character arrays, 
//you can use the C++ string getline() function to read lines into strings
bool CSVParse::openFile(const char* fileName)
{
    string pathKey = CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName);
    ifstream fin(pathKey.c_str());  
    string s;  
    
    while(::getline(fin,s))
    {   
        CCLOG("%s",s.c_str());
        vector<string> field;
        split(field,s);
        data.push_back(field);
        cols=max(cols, (int)field.size());
    }
    
    for (int i=0; i<data.size(); i++) {
        for (int k=0; k<data[i].size(); k++) {
            CCLOG("%s",getData(i, k));
        }
        
    }
    
    return true;
}

////该方法可用于anroid跟ios及windows平台
//
//bool CSVParse::openFile2(const char* fileName)
//{
//
//	const char* xmlConfFullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName);    
//
//	CCFileData csvdata(xmlConfFullPath, "rt");
//	unsigned long size = csvdata.getSize();
//
//	char *pBuffer = (char*) csvdata.getBuffer();
//
//   string  stringData(pBuffer);
//
//	stringstream  strm;
//
//	strm.write(pBuffer, size);
//
//
//	string s;  
//
//    while(::getline(fin,s))
//    {   
//        CCLOG("%s",s.c_str());
//        vector<string> field;
//        split(field,s);
//        data.push_back(field);
//        cols=max(cols, (int)field.size());
//    }
//    
//    for (int i=0; i<data.size(); i++) {
//        for (int k=0; k<data[i].size(); k++) {
//            CCLOG("%s",getData(i, k));
//        }
//        
//    }
//    
//    return true;
//}
