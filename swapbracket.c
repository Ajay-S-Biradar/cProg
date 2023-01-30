#include <bits/stdc++.h>

using namespace std;
int minSwaps(string s) {
        stack<int> a;
        for(int i=0;i<s.size();i++){

            if(s[i]==']' && !a.empty() &&a.top()=='['){
                a.pop();
                cout<<'k' ;
            }
            else if(s[i]=='['){
                a.push(s[i]);
                //cout<<'k' ;
            }
            if(s[i] == ']'){
                a.push(s[i]);
                cout<<'k' ;
            }
            //cout<<'k' ;
    }
        float f = a.size()/4.0 ;
        return round(f);
    }

int main()
{
    string n = "]]][[[";
    int a = minSwaps(n);
    cout<<a;

    return 0;
}

