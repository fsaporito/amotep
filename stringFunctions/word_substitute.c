/* word_substitute.c */

#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void word_substitute (char *line, int n, char *string, int len; char *oldword, int len_old, char *newword, int len_word, int mode, int *vector) {

	int i; // First For Cycle Variable
	int t; // Second For Cycle Variable
	int count_occ = 0; // Substitution Occurred
	int diff = 0; // Valore Di CAmbio Dell'indice
	
	
	switch (mode) {
		
		case '1': { // #newword < #oldword	
			
			for (i = 0; i <= len; i++) {
			
				if ( vector[i] == 0 ) { 
					
					strcpy(string[i], line[ i + diff ] ); 
					
				} else {
					 
					for ( t = 0; t <= len_new; t++) { 
						
						strcpy(string[i+t], newword[t]); 
						
					}
					
					i += len_new - 1; // -1 Because Of i++, it goes directly to the first char after oldword
					
					count_occ++; 
					
					diff = count_occ*(len_old - len_new);
				
				}
			
			}
			
			break;
		
		}
  
		case '2': { // #newword > #oldword  
			
			for ( i = 0; i <= len; i++) {
			
				if ( vector[i] == 0 ) { 
					
					strcpy (string[i], line[i-diff]); 
					
				} else { 
					
					for ( t = 0; t <= len_new; t++) { 
						
						strcpy (string[i+t], newword[t]); 
						
					}
					
					i += len_new - 1; // -1 Because Of i++, it goes directly to the first char after oldword
					
					count_occ++; 
					
					diff = count_occ*(len_new - len_old);
					
				}	
			
			}
			
			break;
		
		}
  
		case '3' : { // #newword = #oldword  
			
			for ( i = 0; i <= len; i++) {
			
				if ( vector[i] == 0 ) { 
					
					strcpy (string[i], line[i]); 
					
				} else { 
			
					for ( t = 0; t <= len_new; t++) { 
						
						strcpy (string[i+t], newword[t]); 
						
						i += len_new - 1;  // -1 Because Of i++, it goes directly to the first char after oldword
					
					}	
				
				}					
			
			}	
			
			break;
		
		}
	
	}
	
}
