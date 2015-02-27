/*
 * Integer to Roman
 *
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 */

/* C solution */
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


/* Java solution */
public class Solution {
    public String intToRoman(int num) {
        String m = "IVXLCDM";
        StringBuilder str = new StringBuilder();
        int digit, i = 0;
        
        while (num > 0) {
            digit = num % 10;
            num = num / 10;
            StringBuilder tmp = new StringBuilder();
            
            switch (digit) {
                case 3:
                    tmp.insert(0, m.charAt(i));
                case 2:
                    tmp.insert(0, m.charAt(i));
                case 1:
                    tmp.insert(0, m.charAt(i));
                    break;
                case 4:
                    tmp.insert(0, m.charAt(i+1));
                    tmp.insert(0, m.charAt(i));
                    break;
                case 5:
                    tmp.insert(0, m.charAt(i+1));
                    break;
                case 8:
                    tmp.insert(0, m.charAt(i));
                case 7:
                    tmp.insert(0, m.charAt(i));
                case 6:
                	tmp.insert(0, m.charAt(i));
                    tmp.insert(0, m.charAt(i+1));
                    break;
                case 9:
                    tmp.insert(0, m.charAt(i+2));
                    tmp.insert(0, m.charAt(i));
                    break;
                default:
                    break;
            }
            str.insert(0, tmp);
            i += 2;
        }
        
        return str.toString();
    }
}

