//
// Created by Aldrin on 17-01-2024.
//

#ifndef DOOCS_POW_H
#define DOOCS_POW_H
#include "bits/stdc++.h"
using namespace std;

class Pow {
public:
    // Binary Exponentiation Approach
    /**
     * 2 ^ 10 = (2 * 2) ^ 5
     * 4 ^ 5 = 4 * 4 ^ 4
     * 4 ^ 4 = (4 * 4) ^ 2
     * 16 ^ 2 = (16 * 16) ^ 1
     * 256 ^ 1 = 256 * 256 ^ 0 = 256
     * **/
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n < 0) {
            n = abs(n);
            x = 1 / x;
        }
        if(n % 2 == 1)
            return x * myPow(x, n - 1);
        return myPow(x * x, n / 2);
    }


    void generate(int i,int k,vector<string>&v, string s) {
        if(i==k) {
            v.push_back(s);
            return;
        }

        generate(i+1,k,v,s+'0');

        if(i>0 && s[i-1]!='1' ||i==0 )
            generate(i+1,k,v,s+'1');

    }
    vector<string> generateString(int k) {
        vector<string> v;
        generate(0,k,v,"");
        return v;

    }


};


#endif //DOOCS_POW_H
