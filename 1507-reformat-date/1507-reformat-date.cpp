// is input always valid
// output should have leading zeros for day ands month. 

// I split the input into day, moth and year using stringstream
// then i remove the suffix of day and add leading zero and used a month map to convert month names to numeric format. 
// at last i will joined everything in yyy -mm -dd format. 

class Solution {
public:
    string reformatDate(string date) {
        // Step 1: Create a map for converting month to their numeric form. 
        // this will help me convert "jan" - "01"
        unordered_map<string, string> months = {
            {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
            {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
            {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
        };
        
        // Step 2: Split the input date stringg into three part: day, month and year
        stringstream ss(date);
        string day, month, year;
        ss >> day >> month >> year;

        // Step 3: Remove the suffix 'st', 'nd', 'rd', 'th' from day
        day = day.substr(0, day.size() - 2);

        // Step 4: Add leading zero if the day has only one digit 
        if (day.size() == 1)
            day = "0" + day;

        // Step 5: Build final result in YYYY-MM-DD format
        // using the converted month and formatted day 
        return year + "-" + months[month] + "-" + day;
    }
};
// Time complexity - O(1) — because the input is always a fixed small format (no loops over large data).

// Space complexity - O(1) space — only a few string operations.
//If they ask “Can you do it without stringstream?”, you can say:
// Yes, we can manually parse the string using spaces or find substrings using find() and substr() — but using stringstream makes the code cleaner and more readable