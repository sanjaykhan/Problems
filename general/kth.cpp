
#include <cstdio>
#include <algorithm>

using namespace std;

class Solution
{
    public:
    //Function to find the kth smallest element in the array.
    int kthSmallest(int arr[], int n, int k)
    {
        // Your code here
        int kth = lomutoPartition(arr, 0, n - 1, k);
		printf("kth: %d\n", kth);
		return kth;
    }

    int lomutoPartition(int arr[], int l, int r, int k)
    {
        printf("%d %d %d\n", l, r, k);

        if (l - r == 0) return arr[l];
		if (l - r == 1) {
			if (arr[l] > arr[r]) {
				swap(arr[l], arr[r]);
			}
			if (k == l) return arr[l];
			if (k == r) return arr[r];
		}

        int pivot = arr[r];
        int i = l;
        for (int j = l; j < r; j++) {
            if (arr[j] < pivot) {
                swap(arr[j], arr[i]);
                i++;
            }
        }
        /* if (i < r - 1) */ swap(arr[r], arr[i]);

        for (int m = l; m <= r; m++) {
            printf("%d ", arr[m]);
        }
        printf(": %d\n", i);

        //return 0;

        if (i == k - 1) {
            return arr[i];
        } else if (i < k - 1) {
            return lomutoPartition(arr, i + 1, r, k);
        } else {
            return lomutoPartition(arr, l, i - 1, k);
        }
    }
};

int
main()
{
	int arr[] { 3, 5, 4, 2, 9 };
	int n = 5;
	int k = 4;
	Solution s;
	s.kthSmallest(arr, n, k);
}
