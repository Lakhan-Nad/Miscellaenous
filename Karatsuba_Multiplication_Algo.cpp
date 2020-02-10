#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string add_string(string a, string b){
    if(b.length() == 0){
        return a;
    }
    else if(a.length() == 0){
        return b;
    }
    else{
        int ai = a.length() - 1;
        int bi = b.length() - 1;
        int remainder = 0;
        int sum;
        string result;
        while(ai >= 0 && bi >= 0){
            sum = a[ai]-'0' + b[bi] - '0' + remainder;
            result.push_back(sum%10 + '0');
            remainder = sum/10;
            ai--;
            bi--;
        }
        while(ai >= 0){
            sum = a[ai] - '0' + remainder;
            result.push_back(sum%10 + '0');
            remainder = sum/10;
            ai--;
        }
        while(bi >= 0){
            sum = b[bi] - '0' + remainder;
            result.push_back(sum%10 + '0');
            remainder = sum/10;
            bi--;
        }
        if(remainder > 0){
            result.push_back(remainder + '0');
        }
        reverse(result.begin(), result.end());
        return result;
    }
}

string karatsuba(string a, string b){
    if(a.length() == 0 || b.length() == 0){
        return "";
    }
    else if(a.length() == 1 && b.length() == 1){
        int x = a[0] - '0';
        int y = b[0] - '0';
        int result = x * y;
        string res;
        if(result/10 > 0){
            res.push_back(result/10 + '0');
        }
        if(((result/10) > 0) || ((result%10) > 0)){
            res.push_back(result%10 + '0');
        }
        return res;
    }
    else{
        int x = a.length();
        int y = b.length();
        x = x/2;
        y = y/2;
        string p11;
        string p12;
        for(int i = 0; i < a.length() - x; i++){
            p11.push_back(a[i]);
        }
        for(int i = a.length() - x; i < a.length(); i++){
            p12.push_back(a[i]);
        }
        string p21;
        string p22;
        for(int i = 0; i < b.length() - y; i++){
            p21.push_back(b[i]);
        }
        for(int i = b.length() - y; i < b.length(); i++){
            p22.push_back(b[i]);
        }
        string r1 = karatsuba(p11,p21);
        string r2 = karatsuba(p11, p22);
        string r3 = karatsuba(p12, p22);
        string r4 = karatsuba(p12, p21);
        for(int i = 0; i < (x + y); i++){
            r1.push_back('0');
        }
        for(int i = 0; i < x; i++){
            r2.push_back('0');
        }
        for(int i = 0; i < y; i++){
            r4.push_back('0');
        }
        string result;
        result = add_string(r1,r2);
        result = add_string(result,r3);
        result = add_string(result, r4);
        return result;
    }
} 

int main(){
    string a,b;
    cin >> a >> b;
    cout << karatsuba(a,b) << endl;
    return 0;
}