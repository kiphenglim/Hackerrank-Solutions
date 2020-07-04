/**
 * Given a 6x6 2D array, arr:
 *  1 1 1 0 0 0
    0 1 0 0 0 0
    1 1 1 0 0 0
    0 0 0 0 0 0
    0 0 0 0 0 0
    0 0 0 0 0 0
 * We define an hourglass in A to be a subset of valies with indices falling
 * in this pattern in arr's graphical representation:
 *  a b c 
 *    d
 *  e f g
 * 
 * There are 16 hourglasses in arr, and an hourglass sum is the sum of an 
 * hourglass' values. Calculate the hourglass sum for every hourglass in arr,
 * then print the maximum hourglass sum.
 * 
 * 
 * For example, given the 2D array:
 * -9 -9 -9  1 1 1 
    0 -9  0  4 3 2
    -9 -9 -9  1 2 3
    0  0  8  6 6 0
    0  0  0 -2 0 0
    0  0  1  2 4 0

 * We calculate the following 16 hourglass valies:
 * -63, -34, -9, 12, 
   -10, 0, 28, 23, 
   -27, -11, -2, 10, 
   9, 17, 25, 18
 * 
 * Our highest hourglass value is 28.
 */

#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr)
{
  // a[i+0][j] a[i+0][j+1] a[i+0][j+2]
  //           a[i+1][j+1]
  // a[i+2][j] a[i+2][j+2] a[i+2][j+3]
  int max = INT_MIN;

  for (int i = 0; i < arr.size() - 2; ++i)
  {
    for (int j = 0; j < arr.size() - 2; ++j)
    {
      int sum = arr[i + 0][j] + arr[i + 0][j + 1] + arr[i + 0][j + 2] + arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];

      if (sum > max)
        max = sum;
    }
  }

  return max;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  vector<vector<int>> arr(6);
  for (int i = 0; i < 6; i++)
  {
    arr[i].resize(6);

    for (int j = 0; j < 6; j++)
    {
      cin >> arr[i][j];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  int result = hourglassSum(arr);

  fout << result << "\n";

  fout.close();

  return 0;
}
