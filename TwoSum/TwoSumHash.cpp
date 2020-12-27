//Solution using hash map approach

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  vector<int> indices;
  map<int, int> numsMap;

  for (int i = 0; i < nums.size(); i++) {
      numsMap.insert(pair<int, int>(nums[i], i));
  }

  for(int j = 0; j < nums.size(); j++) {
      int numTwo = target - nums[j];
      if (numsMap.count(numTwo) > 0 && numsMap.at(numTwo) != j) {
          indices.push_back(j);
          indices.push_back(numsMap.at(numTwo));
          break;
      }
  }

  return indices;
}

void printVector(vector<int> vec){
  cout << "[";
	for(int i = 0; i < vec.size() - 1; i++){
		cout << vec.at(i) << ", ";
	}
	cout << vec.at(vec.size() - 1) << "]";
}

int main() {
  vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
  nums.push_back(15);

  cout << "Input: ";
  printVector(nums);
  cout << endl;
	cout << "Output: ";
  printVector(twoSum(nums, 9));
  cout << endl;
  cout << "Expected: " << "[0, 1]" << endl;

  return 0;
}
