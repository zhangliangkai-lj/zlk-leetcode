//
// Created by zlk on 1/18/23.
//


#include <gtest/gtest.h>

class MyLinkedList {
  struct Node {
    int val;
    Node *next;
    Node *prev;
    explicit Node(int v) : val(v), next(nullptr), prev(nullptr) {}
  };
  Node *dummy_;
  int sz_;
  Node *getIndexNode(int index) const {
    if (index >= sz_) {
      return dummy_;
    }
    auto p = dummy_->next;
    while (index) {
      --index;
      p = p->next;
    }
    return p;
  }
 public:
  MyLinkedList() : dummy_(new Node(0)), sz_(0) {
    dummy_->next = dummy_;
    dummy_->prev = dummy_;
  }
  ~MyLinkedList() {
    auto p = dummy_->next;
    while (p != dummy_) {
      auto next = p->next;
      delete p;
      p = next;
    }
  }
  int get(int index) const {
    auto node = getIndexNode(index);
    return node == dummy_ ? -1 : node->val;
  }
  void addAtHead(int val) {
    ++sz_;
    auto node = new Node(val);
    node->next = dummy_->next;
    node->prev = dummy_;
    dummy_->next->prev = node;
    dummy_->next = node;
  }

  void addAtTail(int val) {
    ++sz_;
    auto node = new Node(val);
    node->prev = dummy_->prev;
    node->next = dummy_;
    dummy_->prev->next = node;
    dummy_->prev = node;
  }

  void addAtIndex(int index, int val) {
    if (index > sz_) {
      return;
    }
    if (index == sz_) {
      addAtTail(val);
      return;
    }
    auto target = getIndexNode(index);
    auto node = new Node(val);
    node->next = target;
    node->prev = target->prev;
    target->prev->next = node;
    target->prev = node;
    ++sz_;
  }

  void deleteAtIndex(int index) {
    auto node = getIndexNode(index);
    if (node == dummy_) {
      return;
    }
    node->next->prev = node->prev;
    node->prev->next = node->next;
    delete node;
    --sz_;
  }
};

TEST(leetcode, 707) {
  MyLinkedList l;
  l.addAtHead(1);
  l.addAtTail(3);
  l.addAtIndex(1, 2);
  ASSERT_EQ(l.get(1), 2);
  l.deleteAtIndex(1);
  ASSERT_EQ(l.get(0), 1);
  ASSERT_EQ(l.get(1), 3);
}