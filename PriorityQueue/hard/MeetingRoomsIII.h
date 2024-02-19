//
// Created by Aldrin on 19-02-2024.
//

#ifndef DOOCS_MEETINGROOMSIII_H
#define DOOCS_MEETINGROOMSIII_H
#include "bits/stdc++.h"
using namespace std;

class MeetingRoomsIII {
public:
        int mostBooked(int n, vector<vector<int>>& meetings) {
            vector<int> meetingCount(n, 0);
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> usedRooms;
            priority_queue<int, vector<int>, greater<int>> unusedRooms;
            for (int i = 0; i < n; i++) {
                unusedRooms.push(i);
            }
            sort(meetings.begin(), meetings.end());

            for (auto meeting : meetings) {
                int start = meeting[0], end = meeting[1];

                while (!usedRooms.empty() && usedRooms.top().first <= start) {
                    int room = usedRooms.top().second;
                    usedRooms.pop();
                    unusedRooms.push(room);
                }
                if (!unusedRooms.empty()) {
                    int room = unusedRooms.top();
                    unusedRooms.pop();
                    usedRooms.push({end, room});
                    meetingCount[room]++;
                } else {
                    auto [roomAvailabilityTime, room] = usedRooms.top();
                    usedRooms.pop();
                    usedRooms.push({roomAvailabilityTime + end - start, room});
                    meetingCount[room]++;
                }
            }

            int maxMeetingCount = 0, maxMeetingCountRoom = 0;
            for (int i = 0; i < n; i++) {
                if (meetingCount[i] > maxMeetingCount) {
                    maxMeetingCount = meetingCount[i];
                    maxMeetingCountRoom = i;
                }
            }
            return maxMeetingCountRoom;
        }
        //----------------------------------------------------------------------------------------------------------------------------------------------------
        /*
         * using ll = long long;
        using pii = pair<ll, int>;
        class Solution {
        public:
            int mostBooked(int n, vector<vector<int>>& meetings) {
                vector<int> bookings(n, 0);
                priority_queue<int, vector<int>, greater<int>> idle;
                priority_queue<pii, vector<pii>, greater<pii>> busy;
                sort(meetings.begin(), meetings.end());
                for(int i=0;i<n;i++)
                    idle.push(i);

                for(auto meeting:meetings) {
                    int start = meeting[0], end = meeting[1];

                    // if meeting has completed remove it from busy
                    // and add the room id to idle queue
                    while(!busy.empty() and busy.top().first <= start) {
                        idle.push(busy.top().second);
                        busy.pop();
                    }
                    int i = 0;
                    // allocate room if rooms are available
                    if(!idle.empty()) {
                        i = idle.top();
                        busy.push({end, i});
                        idle.pop();
                    }
                    else {
                        // if all rooms are full, then recalculate the end time
                        auto room = busy.top();
                        i = room.second;
                        busy.pop();
                        busy.push({room.first + end - start, i});
                    }
                    bookings[i]++;
                }

                int ans = 0;
                for(int i=0;i<n;i++) {
                    if(bookings[ans] < bookings[i]) {
                        ans = i;
                    }
                }
                return ans;
            }
};
         */
};


#endif //DOOCS_MEETINGROOMSIII_H
