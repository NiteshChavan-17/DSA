#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Paste your threeSum() function here

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;

    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {

        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {

            int targetSum = nums[i] + nums[l] + nums[r];

            if (targetSum == 0)
            {
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[l]);
                temp.push_back(nums[r]);
                l++;
                r--;

                ans.push_back(temp);

                while (l < r && nums[l] == nums[l - 1])
                {
                    l++;
                }

                while (l < r && nums[r] == nums[r + 1])
                {
                    r--;
                }
            }
            else if (targetSum > 0)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
    }

    return ans;
}

int main()
{

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> ans = threeSum(nums);

    if (ans.empty())
    {
        cout << "No Triplets Found." << endl;
    }
    else
    {

        cout << "Triplets are:\n";

        for (int i = 0; i < ans.size(); i++)
        {

            cout << "[ ";

            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }

            cout << "]" << endl;
        }
    }

    return 0;
}