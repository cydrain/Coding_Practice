/*
 * String to Integer (atoi)
 *
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases.
 * If you want a challenge, please do not see below and ask yourself
 * what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely
 * (ie, no given input specs). You are responsible to gather all the
 * input requirements up front. 
 *
 */

    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long r = 0;
        int i = 0;
        char c;
        bool start = false;
        bool neg = false;
        
        while (c = str[i]) {
            if (c == ' ') {
                if (start) {
                    break;
                }
            }
            else if (c == '+' || c== '-') {
                if (!start) {
                    neg = (c == '-');
                    start = true;
                }
                else {
                    break;
                }
            }
            else if (c >= '0' && c <= '9') {
                start = true;
                r = r*10 + (c-'0');
                if (!neg && r > INT_MAX) {
                    return INT_MAX;
                }
                if (neg && -r < INT_MIN) {
                    return INT_MIN;
                }
            }
            else {
                break;
            }
            i++;
        }
        return neg ? -r : r;
    }



    int atoi(const char *str) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        long long val = 0;
        bool sign = true;
        
        // skip the white space
        while (*str == ' ') str++;
        if (*str == '+' || *str == '-') {
            sign = (*str == '+') ? true : false;
            str++;
        }
        
        while (*str >= '0' && *str <= '9') {
            val = val*10 + (*str-'0');
            if (sign && val >= INT_MAX) return INT_MAX;
            if (!sign && -val <= INT_MIN) return INT_MIN;
            str++;
        }
        
        return sign ? val : (-val);
    }
