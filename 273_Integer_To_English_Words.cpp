#include<string>
using namespace std;
class Solution {
public:
    string below20[20] = {
        "", "One", "Two", "Three", "Four",
        "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen",
        "Fourteen", "Fifteen", "Sixteen",
        "Seventeen", "Eighteen", "Nineteen"
    };

    string tens[10] = {
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    string convert(int num) {

        if (num == 0)
            return "";

        if (num < 20)
            return below20[num] + " ";

        if (num < 100)
            return tens[num / 10] + " " + convert(num % 10);

        return below20[num / 100] + " Hundred " +
               convert(num % 100);
    }

    string numberToWords(int num) {

        if (num == 0)
            return "Zero";

        string result = "";

        if (num >= 1000000000) {
            result += convert(num / 1000000000) + "Billion ";
            num %= 1000000000;
        }

        if (num >= 1000000) {
            result += convert(num / 1000000) + "Million ";
            num %= 1000000;
        }

        if (num >= 1000) {
            result += convert(num / 1000) + "Thousand ";
            num %= 1000;
        }

        if (num > 0) {
            result += convert(num);
        }

        // Remove trailing spaces
        if (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
        
    }
};