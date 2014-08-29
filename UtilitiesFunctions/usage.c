/* usage.c */

#include <stdio.h>

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
