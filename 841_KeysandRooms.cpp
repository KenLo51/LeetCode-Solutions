class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited{{0}};
        queue<int> q{{0}};
        while (!q.empty()) {
            int t = q.front(); q.pop();
            for (int key : rooms[t]) {
                if (visited.count(key)) continue;
                visited.insert(key);
                if (visited.size() == rooms.size()) return true;
                q.push(key);
            }
        }
        return false;
    }
};