class MyCalendarThree {
public:
    map<int, int> m;
    int maxcount = 0;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int count =0;
        for(auto it = m.begin(); it!=m.end();it++)
        {
            count += it->second;
            maxcount = max(count, maxcount);
        }
        return maxcount;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */