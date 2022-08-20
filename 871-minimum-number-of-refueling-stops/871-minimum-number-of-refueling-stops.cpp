class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int max_reach = startFuel;
        priority_queue<int> pq;
        
        int count = 0;// no of refueling we do
        int index = 0;
        
        while(max_reach < target)
        {
            while(index < stations.size() &&  stations[index][0] <= max_reach)
            {
                pq.push(stations[index][1]);
                index++;
            }
            if(pq.empty()) return -1;
            max_reach += pq.top();
            pq.pop();
            count++;
            
        }
        return count;
        
    }
};