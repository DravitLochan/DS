// getline error handled in this bitch xD
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
using namespace std;

string checkPal(string s){
    // cout << s << "\n";
    string ans = "NO\n";
    int n = s.length();
    for(int i = 0, j = n - 1; i <= j;){
        // cout << i << " " << j << "\n";
        if(s[i] == ' ' || !isalnum(s[i])){
            // cout << s[i];
            ++i;
            continue;
        } if(s[j] == ' ' || !isalnum(s[j])){
            // cout << s[j];
            --j;
            continue;
        }
        s[i] = tolower(s[i]);
        s[j] = tolower(s[j]);
        if(s[i] != s[j]){
            // cout << "s[i] = " << s[i] << "\n" << "s[j] = " << s[j] << "\n";
            return ans;
        }
        // cout << s[i] << s[j] << "\n";
        ++i; 
        --j;    
    }
    return ans = "YES\n";
}

int main() {
    //code
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        cout << checkPal(s);
    }
    return 0;
}