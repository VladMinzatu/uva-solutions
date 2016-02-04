#include <iostream>
#include <vector>
#include <algorithm>

void read(std::vector<int>& nums, int n);

// Weighted Longest Increasing Subsequence
int weighted_lis(const std::vector<int>& nums, const std::vector<int>& weights, bool inc);

int main(int argc, char **argv)
{
    int nof_test_cases;
    std::cin>>nof_test_cases;
    for(int i = 0; i < nof_test_cases; i++)
    {
        int nof_buildings;
        std::cin>>nof_buildings;
        std::vector<int> heights, widths;
        read(heights, nof_buildings);
        read(widths, nof_buildings);

        int increasing_length = 0, decreasing_length = 0;
        increasing_length = weighted_lis(heights, widths, true);
        decreasing_length = weighted_lis(heights, widths, false);

        if(increasing_length >= decreasing_length)
        {
            std::cout<<"Case "<<(i + 1)<<". Increasing ("<<increasing_length<<"). Decreasing ("<<decreasing_length<<")."<<std::endl;
        } 
        else
        {
            std::cout<<"Case "<<(i + 1)<<". Decreasing ("<<decreasing_length<<"). Increasing ("<<increasing_length<<")."<<std::endl;
        }
    }
    return 0;
}

void read(std::vector<int>& nums, int n)
{
    for(int i = 0; i < n; i++)
    {
        int num; std::cin>>num;
        nums.push_back(num);
    }
}

int weighted_lis(const std::vector<int>& nums, const std::vector<int>& weights, bool inc)
{
    if(nums.size() == 0)
        return 0;
    std::vector<int> lis;
    lis.push_back(weights[0]);
    int global_max = weights[0];
    for(int i = 1; i < nums.size(); i++)
    {
        int max = 0;
        for(int j = 0; j < i; j++)
        {
            if(lis[j] > max && (inc ? nums[j] < nums[i] : nums[j] > nums[i]))
            {
                max = lis[j];
            }
        }
        lis.push_back(weights[i] + max);
        if(lis[i] > global_max)
        {
            global_max = lis[i];
        }
    }
    return global_max;
}
