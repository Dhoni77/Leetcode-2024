//
// Created by Aldrin on 06-02-2024.
//

#ifndef DOOCS_ASTEROIDCOLLISION_H
#define DOOCS_ASTEROIDCOLLISION_H
#include "bits/stdc++.h"
using namespace std;

class AsteroidCollision {
public:
    /*
     * Good Explanation
     * https://leetcode.com/problems/asteroid-collision/description/comments/1977611
     */
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;

        for(int i=0;i<n;i++) {
            if(st.empty() and asteroids[i] < 0)
                continue;
            if(asteroids[i] > 0) {
                st.push(i);
                continue;
            }
            if(!st.empty() and asteroids[st.top()] > abs(asteroids[i])) {
                asteroids[i] = 0;
                continue;
            }
            if(!st.empty() and asteroids[st.top()] <= abs(asteroids[i])){
                while(!st.empty() and asteroids[st.top()] <= abs(asteroids[i])) {
                    if(abs(asteroids[i]) == asteroids[st.top()]) {
                        asteroids[i] = 0;
                        asteroids[st.top()] = 0;
                        st.pop();
                    }
                    else if(abs(asteroids[i]) > asteroids[st.top()]) {
                        asteroids[st.top()] = 0;
                        st.pop();
                    }
                }
                if(!st.empty()) {
                    asteroids[i] = 0;
                }
            }
        }

        for(int i:asteroids) {
            if(i != 0)
                ans.push_back(i);
        }

        return ans;
    }
    //--------------------------------------------------------------------------------------------------------------------------------
    /*
     * TC: O(N)
     * SC: O(N)
     * https://doocs.github.io/leetcode/en/lc/735/#description
     * class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> stack;

    for (const int a : asteroids)
      if (a > 0) {
        stack.push_back(a);
      } else {  // a < 0
        // Destroy the previous positive one(s).
        while (!stack.empty() && stack.back() > 0 && stack.back() < -a)
          stack.pop_back();
        if (stack.empty() || stack.back() < 0)
          stack.push_back(a);
        else if (stack.back() == -a)
          stack.pop_back();  // Both asteroids explode.
        else                 // stack[-1] > the current asteroid.
          ;                  // Destroy the current asteroid, so do nothing.
      }

    return stack;
  }
};
     */
};


#endif //DOOCS_ASTEROIDCOLLISION_H
