#include <iostream>
#include <string.h>

enum Enum_Direction {init=0,left=1,up=2,leftup=3};

int LCS(char* pch_str1, int n_Len1, char* pch_str2, int n_Len2, Enum_Direction** Directions)
{
    if(n_Len1 <=0 || n_Len2 <=0)
    {
        return 0;
    }
    //record part of sequence lcs length
    // ppn_lcs's row and col start with 1,rather than 0;
    int** ppn_lcs;
    ppn_lcs = new int*[n_Len1];
    for(int i=0; i<n_Len1; i++)
    {
        ppn_lcs[i] = new int[n_Len2];
        for(int j=0; j<n_Len2; j++)
        {
            ppn_lcs[i][j] = 0;
        }
    }
    //dynamic programming
    for(int i=0; i<n_Len1; i++)
    {
        for(int j=0; j<n_Len2; j++)
        {
            // the first row and the first col should be considered addtionally
            if(i==0 || j==0)
            {
                if(pch_str1[i] == pch_str2[j])
                {
                    ppn_lcs[i][j] = 1;
                    Directions[i][j] = leftup;
                }
                else
                {
                    if(i>0)
                    {
                        ppn_lcs[i][j] = ppn_lcs[i-1][j];
                        Directions[i][j] = up;
                    }
                    if(j>0)
                    {
                        ppn_lcs[i][j] = ppn_lcs[i][j-1];
                        Directions[i][j] = left;
                    }
                }
            }
            else if(pch_str1[i] == pch_str2[j])
            {
                ppn_lcs[i][j] = ppn_lcs[i-1][j-1] + 1;
                Directions[i][j] = leftup;
            }
            else if(ppn_lcs[i-1][j] > ppn_lcs[i][j-1])
            {
                ppn_lcs[i][j] = ppn_lcs[i-1][j];
                Directions[i][j] = up;
            }
            else
            {
                ppn_lcs[i][j] = ppn_lcs[i][j-1];
                Directions[i][j] = left;
            }
        }
    }
    /*output ppn_lcs
    for(int i=0; i<n_Len1; i++)
    {
        for(int j=0; j<n_Len2; j++)
        {
            std::cout<<ppn_lcs[i][j]<<"\t";
        }
        std::cout<<std::endl;
    }*/
    int length = ppn_lcs[n_Len1-1][n_Len2-1];
    //std::cout<<length<<std::endl;
    for(int i=0; i<n_Len1; i++)
    {
        delete[] ppn_lcs[i];
    }
    delete[] ppn_lcs;
    return length;
}

void GetReversedLCS(char* pch_str1, int n_End1, char* pch_str2, int n_End2, Enum_Direction** Directions, char* pch_ReversedLCS,int& index)
{
    //length of lcs is less than the min of n_Len1 and n_Len2;
    int i = n_End1;
    int j = n_End2;
    if(i<0 || j<0)
    {
        return;
    }
    if(Directions[i][j] == init)
    {
        return;
    }
    if(Directions[i][j] == leftup)
    {
        pch_ReversedLCS[index] = pch_str1[i];
        index++;
        GetReversedLCS(pch_str1,i-1,pch_str2,j-1,Directions,pch_ReversedLCS,index);
    }
    else if(Directions[i][j] == up)
    {
        GetReversedLCS(pch_str1,i-1,pch_str2,j,Directions,pch_ReversedLCS,index);
    }
    else if(Directions[i][j] == left)
    {
        GetReversedLCS(pch_str1,i,pch_str2,j-1,Directions,pch_ReversedLCS,index);
    }
}

void PrintLCS(char* pch_str1, int n_Len1, char* pch_str2, int n_Len2, Enum_Direction** Directions)
{
    char* pch_ReversedLCS = new char[n_Len1];
    int index = 0;
    std::cout<<"string1:"<<pch_str1<<std::endl;
    std::cout<<"string2:"<<pch_str2<<std::endl;
    std::cout<<"lcs:";
    GetReversedLCS(pch_str1,n_Len1-1,pch_str2,n_Len2-1,Directions,pch_ReversedLCS,index);
    for(int i=index-1; i>=0; i--)
    {
        std::cout<<pch_ReversedLCS[i];
    }
    std::cout<<std::endl;
    delete[] pch_ReversedLCS;
}

int main()
{
    char* pch_str1 = "abcasdfde";
    char* pch_str2 = "absdfgde";
    int n_Len1 = strlen(pch_str1);
    int n_Len2 = strlen(pch_str2);

    Enum_Direction** Directions;
    Directions = new Enum_Direction*[n_Len1];
    for(int i=0; i<n_Len1; i++)
    {
        Directions[i] = new Enum_Direction[n_Len2];
        //init Directions
        for(int j=0; j<n_Len2; j++)
        {
            Directions[i][j] = init;
        }
    }
    LCS(pch_str1,n_Len1,pch_str2,n_Len2,Directions);
    /*
    //output Directions
    for(int i=0; i<n_Len1; i++)
    {
        for(int j=0; j<n_Len2; j++)
        {
            std::cout<<Directions[i][j]<<"\t";
        }
        std::cout<<std::endl;
    }*/

    PrintLCS(pch_str1,n_Len1,pch_str2,n_Len2,Directions);

    for(int i=0; i<n_Len1; i++)
    {
        delete[] Directions[i];
    }
    delete[] Directions;
}
