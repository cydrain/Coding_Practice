/*
 * Encode and Decode Strings
 *
 * Design an algorithm to encode a list of strings to a string. The encoded string
 * is then sent over the network and is decoded back to the original list of strings.
 */
class Codec {
public:

    // Encodes a list of strings to a single string.
    // Format: len1:str1+len2:str2+len3:str3...
    string encode(vector<string>& strs) {
        string res;
        for (auto &s : strs) {
            res.append(to_string(s.length()));
            res.append(":");
            res.append(s);
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        int len = s.length();
        int i = 0, l = 0;
        while (i < len) {
            while (s[i] != ':') {
                l = l*10 + (s[i]-'0');
                i++;
            }
            i++;    // ':'
            strs.push_back(s.substr(i,l));
            i += l;
            l = 0;
        }
        return strs;
    }
};

