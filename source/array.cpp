#include <cstddef>

#include "../header/array.h"

int longueur(const char *chaine){
    int lenght = 0;
    const char *ptr = chaine;

    while(*ptr != '\0'){
        lenght++;
        ptr++;
    }

    return lenght;
}

void copie(char *dest, const char *source){
    const char *ptr = source;
    char *ptr2 = dest;

    while(*ptr != '\0'){
        *ptr2 = *ptr;
        ptr++;
        ptr2++;
    }
}

void concatene(char *dest, const char *source){
    int j, i;
    i = longueur(dest);
    for(j=0; j <= longueur(source); j++, i++){
        dest[i] = source[j];
    }
}

int compare(const char *chaine1, const char *chaine2){
    const char *ptr = chaine1;
    const char *ptr2 = chaine2;

    while(*ptr != '\0' && *ptr2 != '\0'){
        if(*ptr > *ptr2){
            return 1;
        }else
        if(*ptr < *ptr2){
            return -1;
        }

        ptr++;
        ptr2++;
    }

    return 0;
}

char *chercher_char(const char *chaine, char caractere){
    const char *ptr = chaine;

    while(*ptr != '\0'){
        if(caractere == *ptr){
            return const_cast<char*>(ptr);
        }
        ptr++;
    }

    return NULL;
}

void inverse(char *chaine){
    int j = 0;
    int i = longueur(chaine);
    char aux;

    while(j <= i){
        aux = chaine[i - 1]; 
        chaine[i - 1] = chaine[j];
        chaine[j] = aux;

        i--;
        j++;
    }

}

void to_upper(char *chaine){
    char *ptr = chaine;

    while(*ptr != '\0'){
        if(*ptr >= 'a' && *ptr <= 'z'){
            *ptr -= ('a' - 'A');
        }

        ptr++;
    }
}

void to_lower(char *chaine){
    char *ptr = chaine;

    while(*ptr != '\0'){
        if(*ptr >= 'A' && *ptr <= 'Z'){
            *ptr += ('a' - 'A');
        }

        ptr++;
    }
}

char *cherche_mot(const char *phrase, const char *mot){
    int lenght = longueur(mot);
    int i = 0;

    while(phrase[i] != '\0'){
        if(phrase[i] ==  mot[0]){
            int j = 1;
            while(mot[j] != '\0' && phrase[i + j] != '\0' && phrase[i + j] == mot[j] && phrase[i + j] != ' '){
                j++;
            }
            if(j == lenght){
                return (char*)&phrase[i];
            }
        }
        i++;
    }

    return NULL;
}

void sous_chaine(const char *source, char *dest, int debut, int longueur){
    debut--;
    int i = 0;
    int j = debut;
    while(j < debut + longueur && source[j] != '\0'){
        dest[i] = source[j];
        j++;
        i++;
    }

    dest[i] = '\n';
}

void supprime_caractere(char *chaine, char caractere){
    int j = 0;
    int i = 0;
    while(chaine[i] != '\0'){
        if(chaine[i] != caractere){
            chaine[j] = chaine[i];
            j++;
        }
        i++;
    }

    chaine[j] = '\0';
}

int compte_mots(const char *phrase){
    const char *ptr = phrase;
    int count = 0;

    while(*ptr != '\0'){
        if(*ptr == ' '){
            count++;
        }
        ptr++;
    }

    return count + 1;
}