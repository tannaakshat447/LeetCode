class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        int i = 0;

        while(i < n - 1) {
            if(height[i] == 0) {
                i++;
                continue;
            }

            int j = i + 1;
            int block = 0;
            int right = j;
            int maxRight = 0;

            // Search for a wall >= height[i]
            bool found = false;
            while(j < n) {
                if(height[j] >= height[i]) {
                    found = true;
                    break;
                }
                if(height[j] >= maxRight) {
                    maxRight = height[j];
                    right = j;
                }
                block += height[j];
                j++;
            }

            if(found) {
                // Found right wall >= left wall
                water += (j - i - 1) * height[i] - block;
                i = j;
            } else {
                // Use right max if exact wall not found
                block = 0;
                for(int k = i + 1; k < right; k++) {
                    block += height[k];
                }
                water += (right - i - 1) * height[right] - block;
                i = right;
            }
        }

        return water;
    }
};