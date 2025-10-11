class Solution {
public:
    string reformatDate(string date) {
        // Step 1: Create month mapping
        unordered_map<string, string> months = {
            {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
            {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
            {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
        };
        
        // Step 2: Split the date string
        stringstream ss(date);
        string day, month, year;
        ss >> day >> month >> year;

        // Step 3: Remove 'st', 'nd', 'rd', 'th' from day
        day = day.substr(0, day.size() - 2);

        // Step 4: Add leading zero if needed
        if (day.size() == 1)
            day = "0" + day;

        // Step 5: Build final result in YYYY-MM-DD format
        return year + "-" + months[month] + "-" + day;
    }
};
// Time complexity - O(1) — because the input is always a fixed small format (no loops over large data).

// Space complexity - O(1) space — only a few string operations.