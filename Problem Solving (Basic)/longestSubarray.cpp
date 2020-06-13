/**
 * Given an integer array, find the size of the longest subarray that contains 
 * two distinct values, and no two consecutive elements differ by more than 1.
 */

#include <bits/stdc++.h>
#include <iterator>
#include <set>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'longestSubarray' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int longestSubarray(vector<int> arr) {
  size_t currLength, maxLength = 1;
  set<int> distinctValues;

  for(size_t start = 0; start < arr.size(); ++start) {
    // add current element
    distinctValues.insert(arr[start]);

    for(size_t offset = 1; 
      start+offset < arr.size() && // array bound check
      abs(arr[start] - arr[start+offset]) <= 1 &&  // differ by 1 check
      distinctValues.size() <= 2; //only two unique values 
      ++offset) {
        if (distinctValues.size() < 2 || (distinctValues.size() == 2 &&
          distinctValues.find(arr[start+offset]) != distinctValues.end())) {
            ++currLength;
          }
      distinctValues.insert(arr[start+offset]);
    }

    if(currLength > maxLength) {
      maxLength = currLength;
    } 
    
    currLength = 1;
    distinctValues.clear();
  }

  return maxLength;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    int result = longestSubarray(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
