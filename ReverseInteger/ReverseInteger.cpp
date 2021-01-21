#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int reverse(int x) {
  long reverseNum = 0;
  vector<int> numArr;

  while (x != 0) {
    numArr.push_back(x%10);
    x /= 10;
  }

  for (int i = 0; i < numArr.size(); i++) {
    reverseNum += numArr[i] * pow(10, numArr.size() - i - 1);
      //check for nums outside 32-bit range when reversed
      if (reverseNum > pow(2, 31) - 1 || reverseNum < pow(-2, 31)) {
        reverseNum = 0;
        break;
    }
  }

  return reverseNum;
}

int main() {
  cout << "Input: -1534236469" << endl;
  cout << "Output: " << reverse(-1534236469) << endl;
  cout << "Expected: 0" << endl;

  cout << "Input: 3456" << endl;
  cout << "Output: " << reverse(3456) << endl;
  cout << "Expected: 6543" << endl;

  return 0;
}
