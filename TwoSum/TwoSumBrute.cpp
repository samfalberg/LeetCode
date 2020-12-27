//Solution using brute force approach

#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  vector<int> indices;
  int i, j;
  bool foundAnswer = false;

  for (i = 0; i < nums.size(); i++) {
    for (j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
            indices.push_back(i);
            indices.push_back(j);
            foundAnswer = true;
            break;
        }
    }
    if (foundAnswer) {
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
