#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
string Split(const string& str, const string& delims, int maxSplits)
{
    //分割原来的字符串
	vector<string> ret;
	if(str.empty())
		return "";
	//ret.reserve(maxSplits ? maxSplits+1 : 10);
	int numSplits = 0;

	size_t start, pos;
	start = 0;
	do
	{
		pos = str.find_first_of(delims, start);
		if (pos == start)
		{
			start = pos + 1;
		}
		else if (pos == string::npos || (maxSplits && numSplits == maxSplits))
		{
			ret.push_back( str.substr(start) );
			break;
		}
		else
		{
			ret.push_back( str.substr(start, pos - start) );
			start = pos + 1;
		}

		start = str.find_first_not_of(delims, start);
		++numSplits;

	} while (pos != string::npos);

	//转换成json
	string res = "{";
	size_t i;
	int c = 0;
	const string str = ","
    for(i =0; i < ret.size(); i ++)
    {
        res = res + ret[i] + ",";
        c++;
    }
    int len = str.length() + c;
    res[len-2] = '}';

	return res;
}


int main()
{
    const string str = "&";
    string test = "data1=value1&data2=value2&data3=value3";
    int flag = 1;
    //判断是否需要进行格式转换
    int i;
    for(i=0;i<test.length();i++)
    {
        if(test[i]=='=')
        {
            flag = 1;
            break;
        }
    }
    if(flag==1)
    {
        string  myres = Split(test, str, 100000);
        printf("%s\n",myres.c_str());
    }
    else printf("%s\n",test.c_str());
    return 0;
}
