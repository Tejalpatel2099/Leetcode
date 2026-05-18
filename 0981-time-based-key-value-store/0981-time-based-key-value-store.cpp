// I will store each key with alist of timestamp value pairs  

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {}

// when set is called i will add timestamp and value to that keys list 
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

// when get is called i first check if key exist or not if not then return empty string and if key key exits i will do binary search through that. key timestamop list to find latest timestamp that is less athn or equal to given timestamp. 
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        }

        vector<pair<int, string>> &arr = mp[key];

        int left = 0;
        int right = arr.size() - 1;
        string ans = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid].first <= timestamp) {
                ans = arr[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};

// set - 0(1) 
// get - O(log n) 
// space will be O(total number of set calls)

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */