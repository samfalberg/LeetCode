// Solution with improved runtime due to no helper funtion calls

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Prints linked list to terminal
void printLinkedList(ListNode* head) {
  ListNode* temp;
  temp = head;

  cout << "[";
  while (temp->next != NULL) {
    cout << temp->val << ", ";
    temp = temp->next;
  }
  cout << temp->val << "]" << endl;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  int sum = 0;
  ListNode* sumList = NULL;
  ListNode** temp = &sumList;

  // Loop through both lists and until no number left in remainder
  while (l1 != NULL || l2 != NULL || sum > 0) {
    if (l1 != NULL) {
        sum += l1->val;
        l1 = l1->next;
    }
    if (l2 != NULL) {
        sum += l2->val;
        l2 = l2->next;
    }
    *temp = new ListNode(sum % 10);
    sum /= 10;
    temp = &(*temp)->next;
  }

  return sumList;
}

int main() {
  ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3, new ListNode(7))));
  ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

  cout << "Input: ";
  printLinkedList(l1);
  printLinkedList(l2);

  cout << "Output: ";
  printLinkedList(addTwoNumbers(l1, l2));

  cout << "Expected: [7, 0, 8, 7]" << endl;

  return 0;
}
