class Solution {
public:
    int reverse(int x) {
        long long r = 0; // While intermidiate the value might exceed 32-bit signed value. As we are said "Assume the environment does not allow you to store 64-bit integers (signed or unsigned)." thats why we are using Long long.
        while(x != 0){// It does not matter the number is Positive or Negative, until the number is 0.
            r = r*10 + x%10; // Normal reverse algorithm
            x /= 10;
        }
        if (r <= INT_MAX && r >= INT_MIN) // -2^31 <= x <= 2^31 - 1. INT_MAX and INT_MIN are already predefined in the macro. I checked.
            return (int)r; // Type casting into Integer
        else
            return 0; // As conditioned.
    }
};