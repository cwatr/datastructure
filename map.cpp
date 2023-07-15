#include<bits/stdc++.h>
using namespace std;

int main()
{
    map< int , int > m1;
    map< int , string > m2;
    map< string , int > m3;
    map< string , string > m4;

    for(int i=0;i<8;i++)
    {
        string s;
        cin>> s;
        m3[s]=m3[s]+1;
    }

    cout<<"number of unique string = "<<m3.size()<<endl;
    cout<<"frequency table"<<endl;
    for(auto x:m3)
        cout<<x.first<<" | "<<x.second<<endl;
}