/* word_upper.c */

#include <ctype.h>

void word_upper (char *str, int n) {

	int i;

	for (i=0; i<n; i++) { 
		
		if ( (str[i]>='a') && (str[i]<='z') ) {
		
			 str[i] -= 32; 
		
		} 
	
	}

}

