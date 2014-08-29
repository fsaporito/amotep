#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/* spaces_dash.h */
void spaces_dash (char *str, int n);


/* spaces_underscore.h */
void spaces_underscore (char *str, int n);


/* word_capitalise_first.h */
void word_capitalise_first (char *str, int n);


/* word_lower.c */
void word_lower (char *str, int n);


/* word_substitute.h */
void word_substitute (char *line, int n, char *string, int len; char *oldword, int len_old, char *newword, int len_word, int mode, int *vector);


/* word_toggle.h */
void word_toggle (char *str, int n);


/* word_upper.c */
void word_upper (char *str, int n);
