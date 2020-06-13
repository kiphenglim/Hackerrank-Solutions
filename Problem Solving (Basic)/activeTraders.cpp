/** 
 * Given an array of all trades made by companies, print in a sorted array all 
 * the companies whose trade was at least 5% of the total volume. 
 */

#include <bits/stdc++.h>
#include <cmath>
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'mostActive' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY customers as parameter.
 */

vector<string> mostActive(vector<string> customers) {
  int vectSize = customers.size();
  int minTrades = ceil(vectSize * 0.05);
  map<std::string, double> numTrades;
  set<string> bigCorps;
  vector<string> output;
  
  for (string corp : customers) {
    ++numTrades[corp];
    if (numTrades[corp] >= minTrades) {
      bigCorps.insert(corp);
    }
  }

  for(string corp : bigCorps) {
    output.push_back(corp);
  }

  std::sort(output.begin(), output.end());

  return output;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string customers_count_temp;
    getline(cin, customers_count_temp);

    int customers_count = stoi(ltrim(rtrim(customers_count_temp)));

    vector<string> customers(customers_count);

    for (int i = 0; i < customers_count; i++) {
        string customers_item;
        getline(cin, customers_item);

        customers[i] = customers_item;
    }

    vector<string> result = mostActive(customers);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
