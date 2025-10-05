class Solution {
public:
    string validIPAddress(string ip) {
        if (count(ip.begin(), ip.end(), '.') == 3) {
            // check IPV4 pattern
            if (ip[ip.size() - 1] == '.') {
                return "Neither";
            }
            stringstream ss(ip);
            string t;
            while (getline(ss, t, '.')) {
                if (t.length() == 0 || t.length() > 3) {
                    return "Neither";
                }
                if (t[0] == '0' && t.length() != 1) {
                    return "Neither";
                }
                for (char c : t) {
                    if (!isdigit(c)) {
                        return "Neither";
                    }
                }
                if (stoi(t) > 255) {
                    return "Neither";
                }
            }
            return "IPv4";

        } else if (count(ip.begin(), ip.end(), ':') == 7) {
            // Check for IPV6 pattern
            if (ip[ip.size() - 1] == ':') {
                return "Neither";
            }
            stringstream ss(ip);
            string t;
            while (getline(ss, t, ':')) {
                if (t.length() == 0 || t.length() > 4) {
                    return "Neither";
                }
                
                for (char c : t) {
                    if (!isxdigit(c)) {
                        return "Neither";
                    }
                }
            }
            return "IPv6";

        }
        return "Neither";
    }
};