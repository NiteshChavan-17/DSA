#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Paste your fourSum() function here
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
    vector<vector<int>>ans;
    int n = nums.size();

    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++) {
        if(i>0 && nums[i]==nums[i-1]) continue;

        for(int j=i+1;j<n;) {
                
            int p = j+1, q = n-1;

            while(p<q) {
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];

                if(sum==target){
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[p]);
                    temp.push_back(nums[q]);

                    ans.push_back(temp);
                    p++;
                    q--;

                    while(p<q && nums[p]==nums[p-1]) p++;
                }
                else if(sum<target) {
                    p++;
                }
                else{
                    q--;
                }
            }

            j++;
            while(j<n && nums[j]==nums[j-1]) j++;
        }
    }

    return ans;
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    vector<vector<int>> ans = fourSum(nums, target);

    if(ans.empty()) {
        cout << "No quadruplets found." << endl;
    }
    else {

        cout << "Quadruplets are:\n";

        for(int i = 0; i < ans.size(); i++) {

            cout << "[ ";

            for(int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << " ";
            }

            cout << "]" << endl;
        }
    }

    return 0;
}