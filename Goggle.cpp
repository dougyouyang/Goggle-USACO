//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;
string word;
char mat[10][10];
int len, sum=0, matb[10][10];
bool fi;

void f(int tf, int pox, int poy)
{
    if(matb[pox][poy]==1)
        return;
    if(fi)
        return;
    if(tf==len){
        sum++, fi=true;
        return;
    }
    int i, j;
    if(tf==0){
        for(i=1;i<=5;i++){
            for(j=1;j<=5;j++){
                if(mat[i][j]==word[tf]){
                    f(tf+1, i, j);
                }
            }
        }
        return;
    }
    matb[pox][poy]=1;
    if(mat[pox-1][poy-1]==word[tf])
        f(tf+1, pox-1, poy-1);
    if(mat[pox-1][poy+1]==word[tf])
        f(tf+1, pox-1, poy+1);
    if(mat[pox+1][poy-1]==word[tf])
        f(tf+1, pox+1, poy-1);
    if(mat[pox+1][poy+1]==word[tf])
        f(tf+1, pox+1, poy+1);
    if(mat[pox][poy+1]==word[tf])
        f(tf+1, pox, poy+1);
    if(mat[pox][poy-1]==word[tf])
        f(tf+1, pox, poy-1);
    if(mat[pox-1][poy]==word[tf])
        f(tf+1, pox-1, poy);
    if(mat[pox+1][poy]==word[tf])
        f(tf+1, pox+1, poy);
    matb[pox][poy]=0;
}

int main()
{
    int i, j;
    for(i=1;i<=5;i++){
        for(j=1;j<=5;j++){
            cin >> mat[i][j];
        }
    }
    
    while (getline(cin,word))
    {
        memset(matb, 0, sizeof(matb));
        len=word.length(), fi=false;
        f(0, 0, 0);
    }
    cin >> word;
    cout << sum-1 << endl;
    
    return 0;
}
