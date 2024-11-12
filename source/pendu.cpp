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

void hanged(){
    srand(time(NULL));

    while(true){
        cout << "** JEU DU PENDU ** \n" << endl;
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
                    cout << "\n Vous avez reussi " << endl;
                    cout << "Voici votre évolution : " << guess_word <<endl;
                    cout << "Continuer ... ";
                    cin >> wait;

                    if(chercher_char(guess_word, '_') == NULL){
                        cout << "\n Vous avez gagner !!!! \n\n";
                        cout << "Voulez vous rejouer? (o/n) : ";
                        cin >> rejouer;
                        if(rejouer == 'o'){
                            ind_word = initialisation(guess_word, lenght);
                            continue;
                        }else{
                            exit(0);
                        }
                    }
                }else
                if(search_char(guess_word, words[ind_word], lettre) != 1){
                    nb_chance += 1;

                    cout << "Vous avez raté" << endl;
                    cout << "Il ne vous reste plus que : " << 8 - nb_chance << " chances ";

                    draw_hanged(nb_chance);
                    cout << "Continuer ... ";
                    cin >> wait;

                    if(nb_chance == 8){
                        cout << "Vous avez perdu !!!! \n";
                        cout << "Voulez vous rejouer? (o/n) : ";
                        cin >> rejouer;
                        if(rejouer == 'o'){
                            ind_word = initialisation(guess_word, lenght);
                            continue;
                        }else{
                            exit(0);
                        }
                    }
                }
                clear();
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

    for(int i=0; i < lenght; i++){
        dest[i] = '_';
    }

    return indice;
}

void draw_hanged(int chance){
    if(chance == 1){
        cout << "\n |\n |   \n |  \n |  \n |\n | \n =====\n\n" << endl;
    }else
    if(chance == 2){
        cout << "\n ____\n |    \n |   \n |  \n |  \n |\n | \n =====\n\n" << endl;
    }else
    if(chance == 3){
        cout << "\n ____\n |   |\n |   \n |  \n |  \n |\n | \n =====\n\n" << endl;
    }else
    if(chance == 4){
        cout << "\n ____\n |   |\n |   o\n |  \n |  \n |\n | \n =====\n\n" << endl;
    }else
    if(chance == 5){
        cout << "\n ____\n |   |\n |   o\n |  / \\ \n |  \n |\n | \n =====\n\n" << endl;
    }else
    if(chance == 6){
        cout << "\n ____\n |   |\n |   o\n |  /|\\ \n |  \n |\n | \n =====\n\n" << endl;
    }else
    if(chance == 7){
        cout << "\n ____\n |   |\n |   o\n |  /|\\ \n |  /  \n |\n | \n =====\n\n" << endl;
    }else
    if(chance == 8){
        cout << "\n ____\n |   |\n |   o\n |  /|\\ \n |  / \\ \n |\n | \n =====";
    }
}