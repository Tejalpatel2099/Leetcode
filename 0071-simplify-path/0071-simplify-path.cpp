class Solution {
public:
    string simplifyPath(string path) {
         vector<string> st;  // acts like a stack
        string token;
        stringstream ss(path);

        // Split by '/'
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                // "" => caused by multiple slashes, ignore
                // "." => current directory, ignore
                continue;
            }
            if (token == "..") {
                // go to parent if possible
                if (!st.empty()) st.pop_back();
            } else {
                // normal folder name (including "..." etc.)
                st.push_back(token);
            }
        }

        // Build final path
        if (st.empty()) return "/";

        string result;
        for (string &dir : st) {
            result += "/" + dir;
        }
        return result;
    
    }
};