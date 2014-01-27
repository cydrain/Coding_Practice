/*
 * Integer to Roman
 *
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 */

    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string roman("IVXLCDM");
        string r;
        int i = 0, digit;
        while (num) {
            digit = num % 10;
            switch (digit) {
                case 0:
                    break;
                case 1:
                case 2:
                case 3:
                    r = string(digit, roman[i]) + r;
                    break;
                case 4:
                    r = string(1, roman[i+1]) + r;
                    r = string(1, roman[i]) + r;
                    break;
                case 5:
                    r = string(1, roman[i+1]) + r;
                    break;
                case 6:
                case 7:
                case 8:
                    r = string(digit-5, roman[i]) + r;
                    r = string(1, roman[i+1]) + r;
                    break;
                case 9:
                    r = string(1, roman[i+2]) + r;
                    r = string(1, roman[i]) + r;
            }
            i += 2;
            num = num / 10;
        }
        return r;
    }
