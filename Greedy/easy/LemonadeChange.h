//
// Created by Aldrin on 10-02-2024.
//

#ifndef DOOCS_LEMONADECHANGE_H
#define DOOCS_LEMONADECHANGE_H
#include "bits/stdc++.h"
using namespace std;

class LemonadeChange {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCount = 0, tensCount = 0, billSize = bills.size();
        for(int i = 0;i<billSize;i++) {
            if(bills[i] == 5) {
                fiveCount++;
            }
            else if(bills[i] == 10) {
                    tensCount++;
                    fiveCount--;
            }
            else {
                if(tensCount > 0) {
                    fiveCount--;
                    tensCount--;
                }
                else {
                    fiveCount -= 3;
                }
            }
            if(fiveCount < 0)
                return false;
        }
        return true;
    }
    //------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
     *  boolean lemonadeChange(vector<int> bills) {
        int five = 0, ten = 0;
        for (int bill: bills) {
            if (bill == 5)
                five++;
            else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } else {
                if (five > 0 && ten > 0) {
                    five--;
                    ten--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
     */
};


#endif //DOOCS_LEMONADECHANGE_H
