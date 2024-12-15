#include <iostream>
#include <map>
using namespace std;



int main() {
  string input = "ABAACCD";
  map<char, int> freq;
  for (auto c:input){
    freq[c]++;
  }

  for (auto kv:freq){
    cout << kv.first << " " << kv.second << endl;
  }
  return 0;

}