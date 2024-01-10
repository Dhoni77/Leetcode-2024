//
// Created by Aldrin on 09-01-2024.
//

#ifndef DOOCS_STRINGTOINTEGER_H
#define DOOCS_STRINGTOINTEGER_H
#include "bits/stdc++.h"
using namespace std;

class StringToInteger {
public:
    int countSubStrings(string str, int k)
    {
        // Write your code here.
        int n = str.size();
        int count = 0;
        for(int i=0;i<n;i++) {
            vector<int> freq(26, 0);
            int distinctCount = 0;
            for(int j=i;j<n;j++) {
                if(freq[str[j]-'a'] == 0) {
                    distinctCount++;
                }
                freq[str[j]-'a']++;
                if(k == distinctCount) {
                    count++;
                }
                else if(distinctCount > k) {
                    break;
                }
            }
        }
        return count;
    }

    int myAtoi(string s) {
        int n = s.size();
        int positive = 0;
        int negative = 0;
        int num = 0;
        int i = 0;

        while(s[i] == ' ') {
            i++;
        }

        if(s[i] == '+') {
            positive++;
            i++;
        }
        else if(s[i] == '-') {
            negative++;
            i++;
        }

        if(positive > 0 and negative > 0) {
            return 0;
        }

        while(i < n and s[i] >= '0' and s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
            i++;
        }

        if(negative > 0)
            num = -num;

        if(num < INT_MIN) {
            return INT_MIN;
        }
        else if(num > INT_MAX) {
            return INT_MAX;
        }

        return num;
    }
    //------------------------------------------------------------------------------------------------------------------------------------------------------
  /**
   *   void trim(string &s) {
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
    }

    int myAtoi(string s) {
        trim(s);
        if(s.empty()) return 0;
        long num = 0;
        int sign = 1;
        if(s[0] == '-') {
            sign = -1;
            s = s.substr(1);
        }else if(s[0] == '+') {
            s = s.substr(1);
        }
        for(char ch: s) {
            if(!isdigit(ch))
                break;
            num = num * 10 + (ch - '0');
            if(num * sign < INT_MIN) {
                return INT_MIN;
            }
            else if(num * sign > INT_MAX) {
                return INT_MAX;
            }
        }
        return sign * num;
    }
   * **/
};


#endif //DOOCS_STRINGTOINTEGER_H
