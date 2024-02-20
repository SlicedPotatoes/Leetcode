class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> *arr;

        if (nums1.size() > nums2.size())
        {
            for (int n : nums2)
            {
                nums1.push_back(n);
            }
            arr = &nums1;
        }
        else
        {
            for (int n : nums1)
            {
                nums2.push_back(n);
            }
            arr = &nums2;
        }
        sort(arr->begin(), arr->end());

        if (arr->size() % 2 == 0)
        {
            int center = arr->size() / 2;
            double med = double(arr->at(center) + arr->at(center - 1)) / 2;
            return med;
        }
        else
        {
            return arr->at(round(arr->size() / 2));
        }
    }
};