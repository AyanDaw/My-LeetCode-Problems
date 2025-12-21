// Check py file for explaining comments


class Solution {
public:
    string intToRoman(int num) {
        string roman = ""; // Answer string
        int pos = 0;       // Position counter: 0=ones, 1=tens, 2=hundreds, 3=thousands

        unordered_map<int, string> dc = {
            {1, "I"}, {5, "V"}, {10, "X"}, {50, "L"},
            {100, "C"}, {500, "D"}, {1000, "M"}
        };

        while (num > 0) {
            int numLast = num % 10; // Last digit
            num /= 10;              // Remove last digit

            if (numLast == 0) {
                pos++;
                continue;
            }

            if (numLast < 4) {
                // 1, 2, 3
                string temp = "";
                for (int i = 0; i < numLast; i++) {
                    temp += dc[(int)pow(10, pos)];
                }
                roman = temp + roman;
            }
            else if (numLast == 4 || numLast == 9) {
                // 4, 9
                int numLastextra = numLast + 1;
                string temp = dc[(int)pow(10, pos)] +
                              dc[numLastextra * (int)pow(10, pos)];
                roman = temp + roman;
            }
            else { // 5, 6, 7, 8
                if (numLast == 5) {
                    string temp = dc[5 * (int)pow(10, pos)];
                    roman = temp + roman;
                } else {
                    int numLastextra = numLast - 5;
                    string temp = dc[5 * (int)pow(10, pos)];
                    for (int i = 0; i < numLastextra; i++) {
                        temp += dc[(int)pow(10, pos)];
                    }
                    roman = temp + roman;
                }
            }

            pos++;
        }

        return roman;
    }
};