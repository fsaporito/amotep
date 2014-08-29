/* spaces_underscore.c */

#include <ctype.h>

void spaces_underscore (char *str, int n) {

	int i;
	
	for (i=0; i<n; i++) { 
		
		if (str[i] == ' ' ) { 
		
			str[i] += 63; // asci(underscore) - asci(spaces) = 95 - 32 = 63
		
		} 
	
	}

}
