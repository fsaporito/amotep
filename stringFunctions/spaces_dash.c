/* spaces_dash.c */

#include <ctype.h>

void spaces_dash (char *str, int n) {

	int i;
	
	for ( i = 0; i < n; i++) { 
		
		if (str[i] == ' ' ) { 
		
			str[i] += 13; // asci(dash) - asci(spaces) = 45 - 32 = 13
		
		} 
	
	}

}
