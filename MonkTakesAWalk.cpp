#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, pos=0;
  string str;
  cin >> t;
  int count = 0;
  while(t--)
  {
    cin >> str;
    int length = str.size();
    pos = 0;
    count = 0;
    while(pos < length)
    {
      int found = str.find_first_of("aeiouAEIOU", pos);
      if(found >= 0)
      {
          count++;
          pos = found+1;
      }
      else
        pos++;
    }
    cout << count << "\n";
  }
  return 0;
}
