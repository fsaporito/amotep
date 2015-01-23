/* word_capitalise_first.c */

#include <ctype.h>

void word_capitalise_first (char *str, int n) {

	if ( ( str[0] >= 'A' ) && ( str[0] <= 'Z' ) ) { 
		
		str[0] += 32;
	
	}

}
