/* word_lower.c */

#include <ctype.h>

void word_lower (char *str, int n) {

	int i;
	
	for (i=0; i<n; i++) { 
		
		if ( (str[i]>='A') && (str[i]<='Z') ) { 
		
			str[i] += 32; 
		
		} 
	
	}

}
