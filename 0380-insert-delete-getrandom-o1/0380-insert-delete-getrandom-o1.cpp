// We need to design a data structure that allows insertion, deletion, and
// returning a random element, all in average O(1) time.
// Questions :- 
// 1. Should I assume all values are integers?
// 2. “Can duplicates exist in the set?” (Usually no, as it's a set.)
// 3. Should getRandom() return each element with equal probability?

//....... Brute force appraoch
//  In the brute force solution, I store all elements in a vector and use linear
//  search to check for existence when inserting or removing elements Insert:
//  Loop through the vector to check if the value exists. If not, push to the
//  back.
// Remove: Loop through the vector to find the element, then erase it.
// getRandom: Use rand() to get a random index in the vector.
// for all opertaions TC is o(n) and sc is o(n)

// .........oprtmized ...........
// To achieve average O(1) for insert, delete, and getRandom, I use two data
// structures: a vector to store values and a hash map to store their indices.
// The challenge is deletion in O(1). So instead of shifting elements in a
// vector, I swap the element to delete with the last element, update the index
// in the map, and then remove the last element.
// Tc:- o(1) and Sc :- o(n)


// To get all operations in O(1) time:

// \U0001f539 Use:
// unordered_map<int, int> — stores val → index in an array

// vector<int> — stores the actual elements for O(1) random access

// Why this works:
// Insert in vector is O(1)

// Delete from unordered_map is O(1), but vector is O(n) — unless we swap with the last element and pop_back, making it O(1)

// Random Access from vector is O(1)

// ✅ 4. Implementation Strategy
// Here’s the step-by-step logic:

// \U0001f538 insert(val)
// If val exists in map, return false.

// Else:

// Add val to end of vector.

// Store its index in the map.

// Return true.

// \U0001f538 remove(val)
// If val doesn't exist in map, return false.

// Else:

// Get its index from map.

// Swap with the last element in vector.

// Update map for swapped element.

// Remove last element and delete val from map.

// Return true.

// \U0001f538 getRandom()
// Use rand() or built-in random to pick an index in the vector.

// Return vec[randomIndex].


class RandomizedSet {
private:
    unordered_map<int, int> valToIndex; // Maps value → index in the data vector
    vector<int> data;                   // Stores all current values

public:
    RandomizedSet() {
        // Constructor doesn't need to define variables again
        // Just initializes the object
    }

    bool insert(int val) {
        if (valToIndex.count(val)) // If val already exists, return false
            return false;

        data.push_back(val);                        // Add to the end of the vector
        valToIndex[val] = data.size() - 1;          // Store its index in the map
        return true;
    }

    bool remove(int val) {
        if (!valToIndex.count(val)) // If val doesn't exist, return false
            return false;

        int index = valToIndex[val];     // Get index of the element to remove
        int last = data.back();          // Get the last element in the vector

        data[index] = last;              // Overwrite val with last element
        valToIndex[last] = index;        // Update index of the moved last element

        data.pop_back();                 // Remove last element
        valToIndex.erase(val);           // Remove val from map

        return true;
    }

    int getRandom() {
        // Return a random element from data
        return data[rand() % data.size()];
    }
};


    /**
     * Your RandomizedSet object will be instantiated and called as such:
     * RandomizedSet* obj = new RandomizedSet();
     * bool param_1 = obj->insert(val);
     * bool param_2 = obj->remove(val);
     * int param_3 = obj->getRandom();
     */