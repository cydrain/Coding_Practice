/*
 * Valid Number
 *
 * Validate if a given string is numeric.
 *
 * Some examples:
 *  "0" => true
 *  " 0.1 " => true
 *  "abc" => false
 *  "1 a" => false
 *  "2e10" => true
 *
 * Note: It is intended for the problem statement to be ambiguous.
 * You should gather all requirements up front before implementing one. 
 *
 */

    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        enum charType {
            INVALID = 0,
            SPACE,
            NUM,
            SIGN,
            DOT,
            EXP,
            MAXTYPE
        };
        int stateTbl[][MAXTYPE] = {
            {-1,  0,  2,  1,  4, -1},       // 0, init state
            {-1, -1,  2, -1,  4, -1},       // 1, get sign symbol
            {-1,  9,  2, -1,  3,  6},       // 2, get num
            {-1,  9,  5, -1, -1,  6},       // 3, get num+dot
            {-1, -1,  5, -1, -1, -1},       // 4, get dot
            {-1,  9,  5, -1, -1,  6},       // 5, get dot+num
            {-1, -1,  8,  7, -1, -1},       // 6, get exp
            {-1, -1,  8, -1, -1, -1},       // 7, get exp+sign
            {-1,  9,  8, -1, -1, -1},       // 8, get exp+sign+num
            {-1,  9, -1, -1, -1, -1}        // 9, done state
        };
        int state = 0;
        char c;
        charType type;
        
        while (*s) {
            if (*s == ' ') {
                type = SPACE;
            }
            else if (*s == '+' || *s == '-') {
                type = SIGN;
            }
            else if (*s == '.') {
                type = DOT;
            }
            else if (*s == 'e' || *s == 'E') {
                type = EXP;
            }
            else if (*s >= '0' && *s <= '9') {
                type = NUM;
            }
            else {
                type = INVALID;
            }
            
            state = stateTbl[state][type];
            if (state == -1) return false;
            s++;
        }
        
        return (state == 2 || state == 3 || state == 5 || state == 8 || state == 9);
    }




    bool isNumber(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // the input string may contain:
        enum charType {
            INVALID = 0,
            SPACE,
            SIGN,
            DIGIT,
            DOT,
            EXP,
            MAX_TYPE
        };
        int stateTbl[][MAX_TYPE] = {
                { -1,  0,  1,  2,  3, -1},   // 0, init state
                { -1, -1, -1,  2,  3, -1},   // 1, sign
                { -1,  8, -1,  2,  4,  5},   // 2, digit
                { -1, -1, -1,  4, -1, -1},   // 3, dot
                { -1,  8, -1,  4, -1,  5},   // 4, (digit+)dot+digit
                { -1, -1,  6,  7, -1, -1},   // 5, digit+exp
                { -1, -1, -1,  7, -1, -1},   // 6, digit+exp+sign
                { -1,  8, -1,  7, -1, -1},   // 7, digit+exp+(sign+)digit
                { -1,  8, -1, -1, -1, -1},   // 8, digit+space
        };
        
        charType type;
        int state = 0;

        while (*s != '\0') {
            if (*s == ' ') {
                type = SPACE;
            }
            else if (*s == '+' || *s == '-') {
                type = SIGN;
            }
            else if (*s == '.') {
                type = DOT;
            }
            else if (*s == 'e' || *s == 'E') {
                type = EXP;
            }
            else if (*s >= '0' && *s <= '9') {
                type = DIGIT;
            }
            else {
                type = INVALID;
            }
            
            state = stateTbl[state][type];
            if (state == -1) return false;
            s++;
        }
        return (state == 2 || state == 4 || state == 7 || state == 8);
    }
