#include <bits/stdc++.h>
using namespace std;

void TOH(int n, int s, int d, int h, int &count){
    count++;
    
    //base case
    if(n==0){
        return;
    }
    
    //rec case
    TOH(n-1,s,h,d,count);
    
    cout<<"move "<<n<<" plate(s) from "<<s<<" to "<<d<<endl;
    
    TOH(n-1,h,d,s,count);
}


int main()
{
    int n=3;
    int s=1, h=2, d=3;
    int count=0;
    
    TOH(n,s,h,d,count);
    cout<<endl<<count;

    return 0;
}
