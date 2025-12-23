// Check the Py file for explaining comments

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == 0)
            return 0;
        bool negative = (dividend < 0) ^ (divisor < 0);
        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);
        long long quo = 0;

        while (dvd >= dvs){
            long long tempdivisor = dvs;
            long long tempquo = 1;
            while (dvd >= (tempdivisor << 1)){
                tempdivisor <<= 1;
                tempquo <<= 1;
            }
            dvd -= tempdivisor;
            quo += tempquo;
        }
        quo = (negative)? -quo: quo;
        return (int)quo;
    }
};