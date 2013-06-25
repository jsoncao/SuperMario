
/**
 *  解析完的数据放到data这个二维数组中，通过getData(int rows,int cols)
 *  获取数据
 **/

#ifndef _CSVPARSE_
#define _CSVPARSE_

#include "cocos2d.h"
#include <stdio.h>

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
class CSVParse {
    
public:
    CSVParse(istream& fin = cin, string sep = ","):
    fieldsep(sep),
    cols(0)
    {}
    ~CSVParse();
private:
    string                      fieldsep;        // separator characters
    vector<vector<string> >     data;
    int                         cols;
    
private:    
    void    split(vector<string>& field,string line);
    int     advplain(const string& line, string& fld, int);
    int     advquoted(const string& line, string& fld, int);
    
public: 
    //打开文件
    bool            openFile(const char* fileName);
    //根据行列获取数据
    const   char*   getData(int rows,int cols);
    //该列是否有此数据
    int             findColsData(int cols,const char* value);
    //得到最大的列数
    inline  int     getCols(){return cols;}
    //得到总共的行数
    inline  int     getRows(){return data.size();}
};

#endif

