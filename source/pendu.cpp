#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "../header/array.h"
#include "../header/pendu.h"

using namespace std;

/*
Pour ce jeu de pendu, nous avons décidé de laisser 8 chances aux joueurs 
*/

const char *words[] = {"chien", "manger", "fleur", "voiture", "etoile", "jardin", "papillon", "montagne", "bateau", "musique"};
int nb_chance = 0;
string choix;
char rejouer;
char wait;
int reset = 0;

void hanged(){
    srand(time(NULL));

    while(true){
        cout << "\033[35m** JEU DU PENDU ** \n\033[0m" << endl;
        cout << "Que voulez vous faire ? " << endl;
        cout << " 1 - faire une partie " << endl;
        cout << " 2 - quitter \n" << endl;
        cout << " Votre choix -> ";
        cin >> choix;
        clear();

        if(choix == "1"){
            char lettre;
            int ind_word = rand()%10;
            int lenght = longueur(words[ind_word]);
            char guess_word[lenght];

            for(int i=0; i < lenght; i++){
                guess_word[i] = '_';
            }

            while(true){
                if(reset == 1){
                    clear();
                    reset = 0;
                }

                guess_word[lenght] = '\0';

                cout << "Voici le mot : " << endl;
                cout << guess_word << "\n" << endl;

                cout << "Quelle lettre choississez vous? \n";
                cout << "Joueur ->";
                cin >> lettre;
                if(lettre >= 'A' && lettre <= 'Z'){
                    lettre += ('a' - 'A');
                }

                if(search_char(guess_word, words[ind_word], lettre) == 1){
                    cout << "\033[32m\nVous avez reussi\033[0m" << endl;
                    cout << "\033[32mVoici votre évolution : " << guess_word <<"\033[0m" <<endl;

                    if(chercher_char(guess_word, '_') == NULL){
                        cout << "\033[32m\nVous avez gagner !!!! \n\n\033[0m";
                        cout << "Voulez vous rejouer? (o/n) : ";
                        cin >> rejouer;
                        if(rejouer == 'o'){
                            reset = 1;
                            ind_word = initialisation(guess_word, lenght);
                            continue;
                        }else{
                            exit(0);
                        }
                    }
                }else
                if(search_char(guess_word, words[ind_word], lettre) != 1){
                    nb_chance += 1;

                    cout << "\033[33m Vous avez raté\033[0m" << endl;
                    cout << "\033[33m Il ne vous reste plus que : " << 8 - nb_chance << " chances \033[0m";

                    draw_hanged(nb_chance);

                    if(nb_chance == 8){
                        cout << "\033[33m\nVous avez perdu !!!! \n\033[0m";
                        cout << "\033[32m Le mot a deviner était "<< words[ind_word] <<"\033[0m" << endl;
                        cout << "Voulez vous rejouer? (o/n) : ";
                        cin >> rejouer;
                        if(rejouer == 'o'){
                            reset = 1;
                            ind_word = initialisation(guess_word, lenght);
                            continue;
                        }else{
                            exit(0);
                        }
                    }
                }
            }
        }else
        if(choix == "quitter"){
            break;
        }
        

    }
}   

void clear(){
    #ifdef _WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}

int search_char(char *dest, const char *chaine, char caractere){
    int i=0;
    int temoin = 0;

    while(dest[i] != '\0'){
        if(chaine[i] == caractere){
            dest[i] = caractere;
            temoin = 1;
        }
        i++;
    }

    return temoin;
}

int initialisation(char *dest, int lenght){
    int indice = rand()%10;

    nb_chance = 0;

    for(int i=0; i < lenght; i++){
        dest[i] = '_';
    }

    return indice;
}

void draw_hanged(int chance){
    if(chance == 1){
        cout << "\033[33m\n |\n |   \n |  \n |  \n |\n | \n =====\n\n\033[0m" << endl;
    }else
    if(chance == 2){
        cout << "\033[33m\n +---+\n |    \n |   \n |  \n |  \n |\n | \n =====\n\n\033[0m" << endl;
    }else
    if(chance == 3){
        cout << "\033[33m\n +---+\n |   |\n |   \n |  \n |  \n |\n | \n =====\n\n\033[0m" << endl;
    }else
    if(chance == 4){
        cout << "\033[33m\n +---+\n |   |\n |   o\n |  \n |  \n |\n | \n =====\n\n\033[0m" << endl;
    }else
    if(chance == 5){
        cout << "\033[33m\n +---+\n |   |\n |   o\n |  / \\ \n |  \n |\n | \n =====\n\n\033[0m" << endl;
    }else
    if(chance == 6){
        cout << "\033[33m\n +---+\n |   |\n |   o\n |  /|\\ \n |  \n |\n | \n =====\n\n\033[0m" << endl;
    }else
    if(chance == 7){
        cout << "\033[33m\n +---+\n |   |\n |   o\n |  /|\\ \n |  /  \n |\n | \n =====\n\n\033[0m" << endl;
    }else
    if(chance == 8){
        cout << "\033[31m\n +---+\n |   |\n |   o\n |  /|\\ \n |  / \\ \n |\n | \n =====\033[0m";
    }
}