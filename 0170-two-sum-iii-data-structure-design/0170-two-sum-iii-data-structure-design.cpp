class TwoSum {
private:
    unordered_map<int, int>
        numCount; // Stores numbers and how many times they appear

public:
    // Constructor: Initializes the internal map (empty initially)
    TwoSum() {}

    // Adds a number to the data structure
    void add(int number) {
        numCount[number]++; // Increment frequency of the number
    }

    // Checks if any two numbers add up to the given value
    bool find(int value) {
        for (auto& pair : numCount) {
            int num = pair.first;
            long long complement = (long long)value - num;

            // Case 1: Complement is a different number
            if (complement != num && numCount.count(complement)) {
                return true;
            }

            // Case 2: Complement is same as the number, need at least two
            // occurrences
            if (complement == num && pair.second > 1) {
                return true;
            }
        }
        return false; // No valid pair found
    }
};

        /**
         * Your TwoSum object will be instantiated and called as such:
         * TwoSum* obj = new TwoSum();
         * obj->add(number);
         * bool param_2 = obj->find(value);
         */