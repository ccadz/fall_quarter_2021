
#include <stdbool.h>
#include "util.h"

bool is_in(char character, char* characters, int len_characters){
	for(int i =0; i < len_characters; ++i){
		if(character == characters[i]){
			return true;
		}
	}
	return false;
}

bool all_same(char* characters, int len_characters){
	for(int i = 1; i < len_characters; ++i){
		if(characters[i] != characters[0]){
			return false;
		}
	}
	return true;
}
