#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        struct compare {
            bool operator()(const pair<int, int>& p1, const pair<int, int>& p2){
                return p1.second > p2.second;
            }
        };
    
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> map;
            for (int i=0; i<nums.size(); i++) {
                map[nums[i]]++;
            }
    
            priority_queue<pair<int, int>, vector<pair<int, int>>, compare> qu;
            for (auto it = map.begin(); it!=map.end(); it++){
                qu.push(*it);
                if (qu.size() > k) {
                    qu.pop();
                }
            }
    
            vector<int> result(k);
            for (int i=k-1; i>=0; i--){
                result[i] = qu.top().first;
                qu.pop();
            }
    
            return result;
    
        }
    };