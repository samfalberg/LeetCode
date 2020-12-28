// Solution using helper function to append nodes to resulting linked list

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

// Appends node to end of linked list, sets node as head if given empty linked list
void append(ListNode** head, ListNode* item) {
  ListNode* last = *head;

  // If given empty linked list, set node to head of list
  if (*head == NULL) {
    *head = item;
  } else { // Find end of linked list and append node
    while (last->next != NULL) {
      last = last->next;
    }
    last->next = item;
  }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  int sum = 0;
  ListNode* sumList = NULL;

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
    append(&sumList, new ListNode(sum % 10));
    sum /= 10;
  }

  return sumList;
}

int main() {
  ListNode* l1 = new ListNode(2);
  append(&l1, new ListNode(4));
  append(&l1, new ListNode(3));
  append(&l1, new ListNode(7));

  ListNode* l2 = new ListNode(5);
  append(&l2, new ListNode(6));
  append(&l2, new ListNode(4));

  cout << "Input: ";
  printLinkedList(l1);
  printLinkedList(l2);

  cout << "Output: ";
  printLinkedList(addTwoNumbers(l1, l2));

  cout << "Expected: [7, 0, 8, 7]" << endl;

  return 0;
}
