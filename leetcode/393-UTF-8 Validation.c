/*
 * UTF-8 Validation
 *
 * A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:
 *
 * For 1-byte character, the first bit is a 0, followed by its unicode code.
 * For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed
 * by n-1 bytes with most significant 2 bits being 10.
 *
 * This is how the UTF-8 encoding would work:
 *
 * Char. number range  |        UTF-8 octet sequence
 *    (hexadecimal)    |              (binary)
 * --------------------+---------------------------------------------
 * 0000 0000-0000 007F | 0xxxxxxx
 * 0000 0080-0000 07FF | 110xxxxx 10xxxxxx
 * 0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
 * 0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 *
 * Given an array of integers representing the data, return whether it is a valid
 * utf-8 encoding. 
 */
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int bytes = 1;
        for (auto c : data) {
            if (bytes == 1) {
                if ((c & 0x80) == 0x0) bytes = 1;
                else if ((c & 0xE0) == 0xC0) bytes = 2;
                else if ((c & 0xF0) == 0xE0) bytes = 3;
                else if ((c & 0xF8) == 0xF0) bytes = 4;
                else return false;
            } else {
                if ((c & 0xC0) != 0x80) return false;
                bytes--;
            }
        }
        return (bytes == 1);
    }
};
