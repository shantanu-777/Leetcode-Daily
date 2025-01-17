class Solution {
private:
    // find next smallest element index
    vector<int> nextSmallest(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        // initialize a stack
        stack<int> s;

        for (int i = n - 1; i >= 0; i--) {
            if (s.empty()) {
                ans[i] = n;
                s.push(i);
            } else {
                if (arr[i] > arr[s.top()]) {
                    ans[i] = s.top();
                    s.push(i);
                } else {
                    while (!s.empty() && arr[i] <= arr[s.top()]) {
                        s.pop();
                    }
                    if (s.empty()) {
                        ans[i] = n;
                        s.push(i);
                    } else {
                        ans[i] = s.top();
                        s.push(i);
                    }
                }
            }
        }
        return ans;
    }
    // find previous smallest element index
    vector<int> prevSmallest(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        // initialize a stack
        stack<int> s;

        for (int i = 0; i < n; i++) {
            if (s.empty()) {
                ans[i] = -1;
                s.push(i);
            } else {
                if (arr[i] > arr[s.top()]) {
                    ans[i] = s.top();
                    s.push(i);
                } else {
                    while (!s.empty() && arr[i] <= arr[s.top()]) {
                        s.pop();
                    }
                    if (s.empty()) {
                        ans[i] = -1;
                        s.push(i);
                    } else {
                        ans[i] = s.top();
                        s.push(i);
                    }
                }
            }
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prevSmallestIndex = prevSmallest(heights);
        vector<int> nextSmallestIndex = nextSmallest(heights);
        vector<int> area(heights.size());
        for (int i = 0; i < heights.size(); i++) {
            area[i] =
                heights[i] * (nextSmallestIndex[i] - prevSmallestIndex[i] - 1);
        }
        return *max_element(begin(area), end(area));
    }
};