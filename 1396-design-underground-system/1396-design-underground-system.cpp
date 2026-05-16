class UndergroundSystem {
private:
// this map is for check in key is customerid and value is  stationname and time pair 
    unordered_map<int, pair<string ,int>> checkin;
    // this map is for route key (s1 + s2) value is totaltime , totalcount pair 
    unordered_map<string, pair<int ,int>> routes;
public:

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string s1 = checkin[id].first;
        int stime = checkin[id].second; 

        string route = s1 + "#" + stationName;
        int traveltime = t - stime;

        routes[route].first = routes[route].first + traveltime;
        routes[route].second = routes[route].second + 1;

        checkin.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string r = startStation + "#" + endStation;

        int totaltime =  routes[r].first;
        int totalcount = routes[r].second;
        double average = (double)totaltime / totalcount;
        return average;

    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */