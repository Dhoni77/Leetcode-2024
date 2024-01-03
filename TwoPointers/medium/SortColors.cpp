//
// Created by Aldrin on 15-03-2022.
//

#include "SortColors.h"

int main(){
    SortColors sc;

    vector<int> num{2, 0, 1};
    sc.sortColors(num);

    for(auto i:num){
        cout << i << "\t";
    }
}
