#include<bits/stdc++.h>


using namespace std;
int main()
{
    int n, i;
    char p;
    vector<int> v;
    vector<char> c;
    for( i=0; i<6;i++)
   { 
       cin>>n;
       v.push_back(n);
   }
    sort(v.begin(), v.end());
    for( i=0;i<6;i++)
    cout<<" "<<v[i];

    for( i=0; i<6;i++)
     { 
       cin>>p;
       c.push_back(p);
   }
    sort(c.begin(), c.end());
    for(i=0;i<6;i++)
    cout<<" "<<c[i];
    

return 0;
}