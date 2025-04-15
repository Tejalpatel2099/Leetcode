// Combine all info into one list of [timestamp, username, website] and sort it by timestamp.

// For each user, collect the list of websites they visited in order.

// From each user’s history, generate all combinations of 3-website sequences.

// Count how many users visited each sequence.

// Return the sequence with highest user count. If there’s a tie, return lexicographically smallest one.

//

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size();

        // Step 1: Create and sort by timestamp
        vector<tuple<int, string, string>> data;
        for (int i = 0; i < n; ++i)
            data.push_back({timestamp[i], username[i], website[i]});
        sort(data.begin(), data.end());

        // Step 2: Group visits by user
        unordered_map<string, vector<string>> userToSites;
        for (auto& [time, user, site] : data)
            userToSites[user].push_back(site);

        // Step 3: For each user, get all unique 3-sequences
        map<vector<string>, set<string>> seqToUsers;
        for (auto& [user, sites] : userToSites) {
            int sz = sites.size();
            set<vector<string>> sequences;
            for (int i = 0; i < sz; ++i) {
                for (int j = i + 1; j < sz; ++j) {
                    for (int k = j + 1; k < sz; ++k) {
                        sequences.insert({sites[i], sites[j], sites[k]});
                    }
                }
            }
            for (auto& seq : sequences)
                seqToUsers[seq].insert(user);
        }

        // Step 4: Find the most common sequence
        vector<string> res;
        int maxCount = 0;
        for (auto& [seq, users] : seqToUsers) {
            if (users.size() > maxCount || (users.size() == maxCount && seq < res)) {
                maxCount = users.size();
                res = seq;
            }
        }

        return res;
    }
};
