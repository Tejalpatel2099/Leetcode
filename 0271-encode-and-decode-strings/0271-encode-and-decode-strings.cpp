class Codec {
public:
   // Encodes a list of strings to a single string.                                                                                             
   std::string encode(std::vector<std::string>& strs) {
     std::ostringstream oss;
     for (int i = 0; i < static_cast<int>(strs.size()); ++i) {
       oss << std::setfill('0') << std::setw(20) << strs[i].size();
       oss << strs[i];
     }
   return oss.str();
 }

 // Decodes a single string to a list of strings.                                                                                             
 std::vector<std::string> decode(std::string s) {
   int i = 0;
   std::vector<std::string> strs;
   while (i <= static_cast<int>(s.size()) - 20) {
     std::istringstream iss(s.substr(i, 20));
     int str_len;
     iss >> str_len;
     i += 20;
     if (str_len > 0)
       strs.push_back(s.substr(i, str_len));
     else
       strs.push_back(std::string(""));                                                                                                       
     i += str_len;
  }
  return strs;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));