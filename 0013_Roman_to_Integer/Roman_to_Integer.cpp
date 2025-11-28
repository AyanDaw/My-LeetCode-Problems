class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> dc = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };                                             // Making a Dictionary first

        int inte = 0;                                  // A variable where i shall store the value
        int i = 0;                                     // A counter variable for loop
        
        while (s[i] != '\0'){                          // Making sure the counter wont get past of the available index
            if( s[i] && (dc[s[i]] < dc[s[i + 1]])){    // Checking if next digit is bigger or not. like IV, IX etc.
                inte += dc[s[i + 1]] - dc[s[i]];       // If true then we will subtract and then add the rest
                i += 2;                                // Ofcourse the next one is already checked so we wont check the next one instead we will skip that
            }
            else{
                inte += dc[s[i]];                      // If false then we will follow the normal path
                i += 1;                                // Then as usual we will check the next one
            }
        }
        return inte;                                   // Returning the integer value
    }
};