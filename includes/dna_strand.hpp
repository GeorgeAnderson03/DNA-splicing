#ifndef DNA_STRAND_HPP
#define DNA_STRAND_HPP

#include "node.hpp"

class DNAstrand {
public:
  DNAstrand() = default;
  DNAstrand(const DNAstrand& rhs) = delete;
  DNAstrand& operator=(const DNAstrand& rhs) = delete;
  ~DNAstrand();

  void PushBack(char letter);
  void SpliceIn(const char* pattern, DNAstrand& to_splice_in);
  int Sequencesize();

private:
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};

#endif