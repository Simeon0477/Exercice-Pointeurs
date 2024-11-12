#ifndef __ARRAY_H__
#define __ARRAY_H__

int longueur(const char *chaine);
void copie(char *dest, const char *source);
void concatene(char *dest, const char *source);
int compare(const char *chaine1, const char *chaine2);
char *chercher_char(const char *chaine, char caractere);
void inverse(char *chaine);
void to_upper(char *chaine);
void to_lower(char *chaine);
char *cherche_mot(const char *phrase, const char *mot);
void sous_chaine(const char *source, char *dest, int debut, int longueur);
void supprime_caractere(char *chaine, char caractere);
int compte_mots(const char *phrase);

#endif