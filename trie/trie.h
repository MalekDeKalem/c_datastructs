
#ifndef TRIE_H
#define TRIE_H

#define ALPHABET_SIZE 26

typedef struct struct trie_node trie_node;

struct trie_node {
	void *value;
	bool is_terminal;
	trie_node *children[ALPHABET_SIZE];
};

struct trie {

};


#endif
