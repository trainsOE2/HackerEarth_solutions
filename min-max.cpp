#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, item, sum=0;
    cin >> n;
    vector<int> arr;
    while(n--)
    {
      cin >> item;
      arr.push_back(item);
      sum += item;
    }
    cout << sum - *max_element(arr.begin(), arr.end()) << ' ' << sum - *min_element(arr.begin(), arr.end());
}
