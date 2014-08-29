/* amotep.c */
//
//
//      Copyright 2012 darkeffe <darkeffe@darkeffe>
//
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.
//
//



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>

#include "usage.h"


int main ( int argc, char **argv ) {

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Definizione Variabili
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	char stdin_input[2] = "-i"; // Input From Stdin
	char stdout_output[2] = "-o"; // Output To Stdout

	char STDIN[5] = "stdin";
	char STDOUT[6] = "stdout";

	char option_dash[2]; // argv[1]
	char option[1]; // Option Without Dash
	int cho; // Choice For The Switch Menu
	
	char help[1] = "h"; // Help Option
	char copy[1] = "c"; // Copy
	char lower[1] = "l"; // Lower
	char upper[1] = "U"; // Upper
	char capitalise[1] = "C"; // Capitalise
	char toggle[1] = "T"; // Toggle

	char input[1024]; // Input
	char output[1024]; // Output




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Controllo E Parsing Argomenti
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	strcpy(option_dash,argv[1]);
	
	strcpy(option[1],option_dash[1]);

	if (strcmp(option,help)==0) { usage(); exit(1); }

	if (argc > 3 ) { fprintf (stderr, "error: Too Many Arguments"); usage(); exit(1); }

	if (argc != 3) { fprintf (stderr, "error: To Few Arguments"); usage(); exit(1); }

	if (strcmp(argv[2],stdin_input)==0) { strcpy(input,STDIN); }
	else { strcpy(input,argv[2]); }
	fprintf (stdout,"[*] Input : %s\n",input);

	if (strcmp(argv[3],stdout_output)==0) { strcpy(output,STDOUT); }
	else { strcpy(output,argv[3]); }
	fprintf (stdout,"[*] Output : %s\n",output);

	
	if (strcmp(option,copy)==0) { cho = 1; } // Copy
	if (strcmp(option,lower)==0) { cho = 2; } // Lower
	if (strcmp(option,upper)==0) { cho = 3; } // Upper
	if (strcmp(option,capitalise)==0) { cho = 4; } // Capitalise
	if (strcmp(option,toggle)==0) { cho = 5; } // Toggle


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Apertura File Input E Output
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	FILE *fpi;
	FILE *fpo;

	fpi = fopen ( input, "r" );
	fpo = fopen ( output, "w" );

	if ( fpi == NULL ) { fprintf (stderr,"error: %s did not opened !!!",input); usage(); exit(1); }
	if ( fpo == NULL ) { fprintf (stderr,"error: %s did not opened !!!",output); usage(); exit(1); }




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Editing File
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	int n; // Lunghezza Effettiva Linea
	char line [ 256 ]; // Stringa Per La Linea Letta
	int i = 0; // Variabile Per Il Calcolo Del Numero Di Righe

	switch(cho) {

		case '1' : { // Copy

			while ( fgets ( line, sizeof line, fpi ) != NULL ) {

				fprintf (fpo,"%s",line); // write the line to file
				i++;

			}

			break;

		}

		case '2' : { // Lower

			while ( fgets ( line, sizeof line, fpi ) != NULL ) {

				n = strlen(line);
				word_lower(line,n);
				fprintf (fpo,"%s",line); // write the line to file
				i++;

			}

			break;

		}

		case '3' : { // Upper


			while ( fgets ( line, sizeof line, fpi ) != NULL ) {

				n = strlen(line);
				word_upper(line,n);
				fprintf (fpo,"%s",line); // write the line to file
				i++;

			}

			break;

		}

		case '4' : { // Capitalise

			while ( fgets ( line, sizeof line, fpi ) != NULL ) {

				n = strlen(line);
				word_capitalise_first(line,n);
				fprintf (fpo,"%s",line); // write the line to file
				i++;

			}

			break;

		}

		case '5' : { // Toggle

			while ( fgets ( line, sizeof line, fpi ) != NULL ) {
				n = strlen(line);
				word_toggle(line,n);
				fprintf (fpo,"%s",line); // write the line to file
				i++;

			}

			break;

		}

		default : {

			fprintf (stderr, "Error: '%s' option not recognised !!!", option);
			
			usage();

			break;

		}

	}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Closing Input & Output
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	fclose ( fpi );
	fclose ( fpo );

	fprintf (stderr,"[*] %s  :  %i  righe scritte :)\n\n",output,i);

	return 0;

}


/* spaces_dash.c */
void spaces_dash (char *str, int n) {

	int i;
	
	for (i=0; i<n; i++) { 
		
		if (str[i] == ' ' ) { 
		
			str[i] += 13; // asci(dash) - asci(spaces) = 45 - 32 = 13
		
		} 
	
	}

}


/* spaces_underscore.c */
void spaces_underscore (char *str, int n) {

	int i;
	
	for (i=0; i<n; i++) { 
		
		if (str[i] == ' ' ) { 
		
			str[i] += 63; // asci(underscore) - asci(spaces) = 95 - 32 = 63
		
		} 
	
	}

}


/* usage.c */
void usage() {

	fprintf (stdout," \n\n");
	fprintf (stdout,"Usage: \n");
	fprintf (stdout,"amotep option [fileinput | -i] [fileoutput | -o]\n\n");

	fprintf (stdout,"Options : ");
	fprintf (stdout,"-h      print this help\n");
	fprintf (stdout,"-c          copy input to output + count lines + speed\n");
	fprintf (stdout,"-l          all letter to lower\n");
	fprintf (stdout,"-U          all letter to upper\n");
	fprintf (stdout,"-C          capitalise the first letter\n");
	fprintf (stdout,"-T          toggle all letter\n");

	fprintf (stdout,"\n\n");

	fprintf (stdout,"Input/Output : \n");
	fprintf (stdout,"-i          take input from stdin\n");
	fprintf (stdout,"-o          write output to stdout\n");

}


/* word_capitalise_first.c */
void word_capitalise_first (char *str, int n) {

	if ( (str[0]>='A') && (str[0]<='Z') ) { 
		
		str[0] += 32;
	
	}

}


/* word_lower.c */
void word_lower (char *str, int n) {

	int i;
	
	for (i=0; i<n; i++) { 
		
		if ( (str[i]>='A') && (str[i]<='Z') ) { 
		
			str[i] += 32; 
		
		} 
	
	}

}


/* word_substitute.c */
void word_substitute (char *line, int n, char *string, int len; char *oldword, int len_old, char *newword, int len_word, int mode, int *vector) {

	int i; // First For Cycle Variable
	int t; // Second For Cycle Variable
	int count_occ = 0; // Conteggio Numero Di Occorrenze Risolte
	int diff = 0; // Valore Di CAmbio Dell'indice
	
	
	switch (mode) {
		
		case '1': { // #newword < #oldword	
			for (i=0; i<=len; i++) {
				if ( vector[i] == 0 ) { strcpy(string[i],line[i+diff]); }
				if ( vector[i] != 0 ) { 
					for (t=0; t<=len_new; t++) { strcpy(string[i+t],newword[t]); }
					i += len_new - 1; // -1 Because Of i++, it goes directly to the first char after oldword
					count_occ++; 
					diff = count_occ*(len_old - len_new);
				}
			}
			break;
		}
  
		case '2': { // #newword > #oldword  
			for (i=0; i<=len; i++) {
				if ( vector[i] == 0 ) { strcpy(string[i],line[i-diff]); }
				if ( vector[i] != 0 ) { 
					for (t=0; t<=len_new; t++) { strcpy(string[i+t],newword[t]); }
					i += len_new - 1; // -1 Because Of i++, it goes directly to the first char after oldword
					count_occ++; 
					diff = count_occ*(len_new - len_old);
				}	
			}
			break;
		}
  
		case '3' : { // #newword = #oldword  
			for (i=0; i<=len; i++) {
				if ( vector[i] == 0 ) { strcpy(string[i],line[i]); }
				if ( vector[i] != 0 ) { 
					for (t=0; t<=len_new; t++) { 
						strcpy(string[i+t],newword[t]); 
						i += len_new - 1;  // -1 Because Of i++, it goes directly to the first char after oldword
					}	
				}					
			}	
			break;
		}
	
	}
	
}


/* word_toggle.c */
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


/* word_upper.c */
void word_upper (char *str, int n) {

	int i;

	for (i=0; i<n; i++) { 
		
		if ( (str[i]>='a') && (str[i]<='z') ) {
		
			 str[i] -= 32; 
		
		} 
	
	}

}

