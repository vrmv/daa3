//
//  horse.cpp
//  
//
//  Created by Harith L K on 27/04/19.
//

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int horsepool(string main,string search){
    int n = main.length();
    int m = search.length();
    int shift[256];
    
    int i,j,s=0;
    
    for(i = 0;i < 256;i++)
        shift[i] = m;
    
    for(i = 0;i < m-1;i++)
        shift[search[i]] = m-i-1;
    
    while(s+m <= n){
        if(search[m-1] == main[s+m-1]){
            i = m-2;
            while(i >= 0 && search[i] == main[s+i]){
                i--;
            }
            if(i == -1)
                return s;
        }
        s = s + shift[main[s+m-1]];
    }
    return s;
}

int main(){
    string main,search;
    
    cout<<"\nEnter the main string : ";
    getline(cin,main);
    
    cout<<"\nEnter the search string : ";
    cin>>search;
    
    int p = horsepool(main,search);
   
    if(p==main.length()){
        cout<<"\nString not found.";
    }
    else
        cout<<"\nString match at the position "<<p+1<<endl;
    
    return 0;
}
