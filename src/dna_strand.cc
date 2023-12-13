#include "dna_strand.hpp"

#include <stdexcept>
DNAstrand::~DNAstrand() {
  while (head_ != nullptr) {
    Node* current = head_->next;
    delete head_;
    head_ = current;
  }
}
void DNAstrand::PushBack(char letter) {
  if (head_ == nullptr) {
    head_ = tail_ = new Node(letter);
  } else {
    Node* temp = new Node(letter);
    tail_->next = temp;
    tail_ = temp;
  }
}
int Patternsize(const char* pattern) {
  int counter = 0;
  for (unsigned int i = 0; pattern[i] != '\0'; i++) {
    counter++;
  }
  return counter;
}
int DNAstrand::Sequencesize() {
  Node* current = head_;
  int counter = 0;
  while (current != nullptr) {
    counter++;
    current = current->next;
  }
  return counter;
}
void DNAstrand::SpliceIn(const char* pattern, DNAstrand& to_splice_in) {
  if (*pattern == 0 || to_splice_in.head_ == nullptr) {return;}
  if (&to_splice_in == this) {return;}
  if (Patternsize(pattern) > Sequencesize() || Patternsize(pattern) == 0) {throw std::invalid_argument("a");}
  Node* current = head_;
  int patternsize = Patternsize(pattern);
  int matches = 0;
  int matchcheck = 0;
  Node* lastnode = head_;
  Node* beforedelete = nullptr;
  Node* afterdelete = nullptr;
  while (current != nullptr) {
    if (current->data == pattern[0]) {
      Node* before = current;
      for (int i = 0; pattern[i] != '\0' && before != nullptr; i++) {
        if (before->data == pattern[i]) {matchcheck++;} else {matchcheck = 0;}
        before = before->next;
      }
      if (matchcheck == patternsize) {beforedelete = lastnode;afterdelete = before;matches++;
      }
      matchcheck = 0;
    }
    lastnode = current;
    current = current->next;
  }
  if (matches > 0) {
    Node* todelete = nullptr;
    if (beforedelete == head_) {todelete = head_;} else {todelete = beforedelete->next;}
    while (todelete != afterdelete) {
      Node* temp = todelete->next;
      delete todelete;
      todelete = temp;
    }
    if (beforedelete == head_) {head_ = to_splice_in.head_;} else {beforedelete->next = to_splice_in.head_;}
    to_splice_in.tail_->next = afterdelete;
    to_splice_in.head_ = nullptr;
    to_splice_in.tail_ = nullptr;
  } else {throw std::invalid_argument("a");}
}