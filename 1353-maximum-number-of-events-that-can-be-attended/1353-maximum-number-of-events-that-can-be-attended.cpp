class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
    // Sort events by start day
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> pq; // Min-heap for end days
        int i = 0, n = events.size();
        int day = 1, attended = 0;

        // Find the last day we may need to process
        int max_day = 0;
        for (auto& e : events) {
            max_day = max(max_day, e[1]);
        }

        // Process each day from 1 to max_day
        while (day <= max_day) {
            // Add all events that start today
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);  // Push end day into min-heap
                i++;
            }

            // Remove all events that have already ended
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // Attend the event that ends earliest
            if (!pq.empty()) {
                pq.pop();  // Attend this event
                attended++;
            }

            day++;
        }

        return attended;
    }
};