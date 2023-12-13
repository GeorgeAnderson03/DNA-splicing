

#include "dna_strand.hpp"

int main() {
  DNAstrand sequence;
  sequence.PushBack('c');
  sequence.PushBack('t');
  sequence.PushBack('g');
  sequence.PushBack('a');
  sequence.PushBack('a');
  sequence.PushBack('t');
  sequence.PushBack('t');
  sequence.PushBack('c');
  // sequence.PushBack('g');
  char pattern1[] = "gaattc";
  DNAstrand to_splice_in;
  to_splice_in.PushBack('b');
  to_splice_in.PushBack('b');

  sequence.SpliceIn(pattern1, to_splice_in);
}