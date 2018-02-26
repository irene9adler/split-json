#include "stdio.h"
#include "cjson.h"
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
int main_()
{

    char str[] ="data1=value1&data2=value2&data3=value3";
    vector<string> ret;
    const char * split1 = "&=";
    char * p;
    p = strtok (str,split1);
    while(p!=NULL) {
            printf ("%s\n",p);
            ret.push_back(p);
            p = strtok(NULL,split1);
    }

//��������Cת����JSON
 char *out;
 cJSON *root;
 root=cJSON_CreateObject();//������Ŀ
 //cJSON_AddItemToObject(root, "name", cJSON_CreateString("Jack (\"Bee\") Nimble"));
 //cJSON_AddItemToObject(root, "format", fmt=cJSON_CreateObject());//����Ŀ�������Ŀ
 size_t i;
 char * key;
 char * value;
 for(i =0; i < ret.size(); i=i+2)
    {
        strcpy(key,ret[i].c_str());
        strcpy(value,ret[i+1].c_str());
        cJSON_AddStringToObject(root,key,value);
    }
 //cJSON_AddStringToObject(fmt,"type", "rect");//����Ŀ�ϵ���Ŀ������ַ�������˵��cJSON�ǿ���Ƕ�׵�
 //cJSON_AddNumberToObject(fmt,"width", 1920);
 //cJSON_AddNumberToObject(fmt,"height", 1080);
 //cJSON_AddNumberToObject(fmt,"frame rate", 24);

 out=cJSON_Print(root);
 printf("%s\n",out);//��ʱoutָ����ַ�������JSON��ʽ����
 free(out);//�ͷſռ�

//����������JSON��ʽ���ת��
return 0;
}
