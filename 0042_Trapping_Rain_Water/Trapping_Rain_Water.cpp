class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = 0, rmax = 0, total = 0, l = 0, r = n-1;
        while(l < r){ // Loop out condition
            // Minimum er opor depend korbe jol kotota dhorbe, so jeta minimum hobe prottek bar seta move korbe
            if (height[l] <= height[r]){
                if(lmax > height[l]) // Ei condition tar mane amar left e current pointer tar ba dike leftmax ache jol dhorar jonno
                total += lmax - height[l];
                // Max ekmatro current pointer theke boro hole tobei count hobe noile jol beriye jabe
                else
                    lmax = height[l]; // Update the lmax.
                l++; // Left jehetu choto so right er dike move korbe
            }
            else{
                if(rmax > height[r]) // Same like left
                    total += rmax - height[r];
                    // Max ekmatro current pointer theke boro hole tobei count hobe noile jol beriye jabe
                else
                    rmax = height[r]; // Update the rmax.
                r--; // Right jehetu choto so left er dike move korbe
            }
            // jokhun e l & r cross korbe eke opor ke loop exit hoye jabe
        }
        return total;
    }
};