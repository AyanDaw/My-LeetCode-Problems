class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(); // Total length of the array
        int lp = 0, rp = n-1; // Two endpoint pointers of The Array
        int mostvol = 0; // A Var to store most volume value ever
        while(lp < rp){
            int width = rp - lp; // distance between two pointers = width of the container
            int hght = min(height[lp],height[rp]); // The total volume always depends on minimum value
            int wtvol = width * hght; // Current water value.
            if (wtvol >= mostvol){
                mostvol = wtvol; // Maximum value getting stored
            }
            (height[lp] > height[rp])? rp-- : lp++; // As the volume only depends on minimum one so to change the volume we are changing the minimum one.
        }
        return mostvol; // Returning the highest value
    }
};