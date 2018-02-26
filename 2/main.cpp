#include <stdio.h>
#include <string.h>

int main ()
{
    char str[] ="data1=value1&data2=value2&data3=value3";
    const char * split1 = "&=";
    const char * a1 = ":";
    const char * a2 = ",";
    const char * a3 = "\"";
    printf("%s\n",a3);
    char * p;
    char res [] = "{";
    //const char * arr = "}";
    int i = 0;
    p = strtok (str,split1);
    while(p!=NULL) {
            printf ("%s\n",p);
            char q[100];
            strcpy(q,p);
            i++;
            if(i%2!=0)
               strcat(q,a1);
            else
               strcat(q,a2);
            printf ("%s\n",q);
            strcat(res,q);

            p = strtok(NULL,split1);
    }

    int len = strlen(res);
    res[len-1] = '}';
    printf ("%s\n",res);
    getchar();
    return 0;

}
