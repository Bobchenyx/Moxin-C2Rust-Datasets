class Solution {
public:
    string toRoman(int num, char one, char half, char whole) {
        string res;
        switch (num) {
            case 3:
                res += one;
            case 2:
                res += one;
            case 1:
                res += one;
                break;
            case 4:
                res += one;
            case 5:
                res += half;
                break;
            case 8:
                res += one;
            case 7:
                res += one;
            case 6:
                res += one;
                res = half + res;
                break;
            case 9:
                res += one;
            case 10:
                res += whole;
                break;
        }
        return res;
    }

    string intToRoman(int num) {
        string res = "";

        // 千位
        int hint = num / 1000;
        if (hint) res += toRoman(hint, 'M', '*', '*');
        num = num % 1000;

        // 百位
        hint = num / 100;
        if (hint) res += toRoman(hint, 'C', 'D', 'M');
        num = num % 100;

        // 十位
        hint = num / 10;
        if (hint) res += toRoman(hint, 'X', 'L', 'C');
        num = num % 10;

        // 个位
        if (num) res += toRoman(num, 'I', 'V', 'X');

        return res;
    }
};