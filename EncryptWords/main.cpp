#include <iostream>
#include <string.h>

using namespace std;

char moveN(char c,int n)
{
    int pos = c - 'a';
    pos = (pos + n)%('z'-'a'+1) +'a';
    char ch = (char)pos;
    return ch;
}

char* encryptWords(char* phrase)
{
    int len = strlen(phrase);
    int k=0;
    for(int i=len-1;i>=0;i--)
    {
        if(phrase[i] == ' ')
        {
            k = 0;
        }else
        {
            phrase[i] = moveN(phrase[i],k);
            k++;
        }
    }
    return phrase;
}

int main()
{
    char pch[1000];
    while(cin.getline(pch,1000))
    {
        cout << encryptWords(pch) << endl;
    }

    return 0;
}
