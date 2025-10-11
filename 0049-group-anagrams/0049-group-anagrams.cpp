// we are given an array of strings and need to group the strings that are anagrams of each other. and i need to return list of groups where each group conatins strings that are anagrams . 

// questions :- 
// 1. Can i assume all strings are lowercase ?
//2 . does the order of groups matter in outptut ? 


//  ... using hash map ......q1 
//  so anagrasm have teh same characters in different order so, if we sort the letters of any two anagrams, the result willbe same string . 
// for eachs tring , sort it , use that sorted string as a key in hash map and store the original(unsorted string ) in value and all anagrams willhave the same sorted key , so they will be grouped together under that key. finally collect allvalues from hash map and retunthem . 
// tc:-  You sort it, which takes O(k log k)
// You do this for n strings → O(n × k log k) and sc :- O(n × k)Storing all strings in groups + keys


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // This hash map will store groups of anagrams
        // Key: sorted version of the string
        // Value: list of original strings that are anagrams of that key
        unordered_map<string, vector<string>> mp;

        // Loop through each string in the input list
        for (int i = 0; i < strs.size(); i++) {
            string sortedString = strs[i]; // Copy the original string
            sort(sortedString.begin(), sortedString.end()); // Sort the characters alphabetically

            // Use the sorted string as a key and add the original string to its group
            mp[sortedString].push_back(strs[i]);
        }

        // Now we need to collect all the grouped anagrams from the map
        vector<vector<string>> anagrams; // This will store the final result

        // Loop through the map
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            anagrams.push_back(it->second); // Add each group (which is a vector of strings) to the result
        }

        return anagrams; // Return all grouped anagrams
    }
};