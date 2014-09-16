/* word_toggle.c */

#include <ctype.h>

void word_toggle (char *str, int n) {

	int i;
	
	for (i=0; i<n; i++) { 
		
		if ( (str[i]>='A') && (str[i]<='Z') ) { 
			
			str[i] += 32; 
		
		} 
		
		if ( (str[i]>='a') && (str[i]<='z') ) { 
		
			str[i] -= 32; 
		
		} 
	
	}

}
