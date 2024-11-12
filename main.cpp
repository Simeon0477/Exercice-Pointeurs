#include <iostream>
#include <string>
#include <cstddef>

#include "header/array.h"
#include "header/pendu.h"

using namespace std;

int choix;
string chaine;

int main(int argc, char** args){
    cout << "Que désirez vous faire?\n";
    cout << " 1 - Calculer la longueur d'une chaine de caractères,\n"
         << " 2 - Copie de chaine de caractères,\n"
         << " 3 - Concaténation de chaines de caractères, \n"
         << " 4 - Comparaison de chaines de caractères, \n"
         << " 5 - Recherche de caractère, \n"
         << " 6 - Inversion de chaine, \n"
         << " 7 - Conversion majuscule/minuscule, \n"
         << " 8 - Trouver un mot dans une phrase, \n"
         << " 9 - Extraction de sous-chaine, \n"
         << " 10 - Suppression de caractère, \n"
         << " 11 - Compter les mots dans une phrase, \n"
         << " 12 - Jouer au pendu \n\n";

    cout << "Votre choix -> ";
    cin >> choix;

    switch(choix){
        case 1 :{
            clear();
            cout << "Calcul de la longueur d'une chaine de caratère\n\n";
            cout << "Entre la chaine de caractère : ";
            cin >> chaine;
            cout << "La longueur de la chaine est de : " << longueur(chaine.c_str()) <<"\n";
            break;
        }
        case 2 :{
            clear();
            cout << "Copie d'une chaine de caratère\n\n";
            cout << "Entre la chaine de caractère : ";
            cin >> chaine;
            char dest[longueur(chaine.c_str())];
            copie(dest, chaine.c_str());
            cout << "La copie de la chaine de caractère est : " << dest <<"\n";
            break;
        }
        case 3 :{
            clear();
            string chaine2;
            cout << "Concatenation de deux chaines de caratère\n\n";
            cout << "Entre la 1ere chaine de caractère : ";
            cin >> chaine;
            cout << "Entre la 2eme chaine de caractère : ";
            cin >> chaine2;
            char dest[longueur(chaine.c_str()) + longueur(chaine.c_str())];
            copie(dest, chaine.c_str());
            concatene(dest, chaine2.c_str());
            cout << "La chaine concatenée est : " << dest <<"\n";
            break;
        }
        case 4 :{
            clear();
            string chaine2;
            cout << "Comparaison lexicographique de deux chaines de caratère\n\n";
            cout << "Entre la 1ere chaine de caractère : ";
            cin >> chaine;
            cout << "Entre la 2eme chaine de caractère : ";
            cin >> chaine2;

            if(compare(chaine.c_str(), chaine2.c_str()) == 0){
                cout << "Les deux chaines sont égales \n";
            }else
            if(compare(chaine.c_str(), chaine2.c_str()) > 0){
                cout << chaine <<" est superieure à " << chaine2 << "\n ";
            }else
            if(compare(chaine.c_str(), chaine2.c_str()) < 0){
                cout << chaine <<" est inferieure à " << chaine2 << "\n ";
            }
            break;
        }
        case 5 :{
            clear();
            char caractere;
            cout << "Recherche d'un caractère dans une chaine de caratère\n\n";
            cout << "Entre la chaine de caractère : ";
            cin >> chaine;
            cout << "Entre le caractère recherché : ";
            cin >> caractere;
            char *position  = chercher_char(chaine.c_str(), caractere);
            
            if(position != NULL){
                cout << "L'adresse de la première occurence de " << caractere << " est : " << &position <<"\n";
            }else{
                cout << "Caractère introuvable \n";
            }

            break;
        }
        case 6 :{
            clear();
            cout << "Inversion d'une chaine de caratère\n\n";
            cout << "Entre la chaine de caractère : ";
            cin >> chaine;
            char dest[longueur(chaine.c_str())];
            copie(dest, chaine.c_str());
            inverse(dest);
            cout << "L'inverse' de la chaine est de : " << dest <<"\n";
            break;
        }
        case 7 :{
            clear();
            cout << "Conversion Majuscule/Minuscule\n\n";
            cout << "Entre la chaine de caractère : ";
            cin >> chaine;
            char dest[longueur(chaine.c_str())];
            copie(dest, chaine.c_str());
            cout << "Que voulez vous faire? : \n 1 - Majuscule \n 2- Minuscule \n";
            cin >> choix;

            if(choix == 1){
                to_upper(dest);
            }else
            if(choix == 2){
                to_lower(dest);
            }
            cout << "La chaine transformée est : " << dest <<"\n";
            break;
        }
        case 8 :{
            clear();
            string mot;
            cout << "Recherche d'un mot dans un phrase\n\n";
            cout << "Entrez la phrase : ";
            cin.ignore();
            getline(cin, chaine);
            cout << "Entrez le mot recherché : ";
            cin >> mot;
            char *position = cherche_mot(chaine.c_str(), mot.c_str());

            if(position != NULL){
                cout << "L'adresse de la première occurence de " << mot << " est : " << &position <<"\n";
            }else{
                cout << "Le mot n'est pas présent dans la phrase\n";
            }
            break;
        }
        case 9 :{
            clear();
            int lenght, ind;
            cout << "Extraction d'une sous-chaine\n\n";
            cout << "Entrez la chaine : ";
            cin.ignore();
            getline(cin, chaine);
            cout << "Entrez la longueur de la sous chaine : ";
            cin >> lenght;
            cout << "Entrez l'indice de début de l'extraction : ";
            cin >> ind;
            char dest[lenght];
            sous_chaine(chaine.c_str(), dest, ind, lenght);

            cout << "La chaine extraite est :" << dest << "\n";
            break;
        }
        case 10 :{
            clear();
            char caractere;
            cout << "Suppression de caratère\n\n";
            cout << "Entre la chaine de caractère : ";
            cin >> chaine;
            cout << "Entre le caractère a supprimer : ";
            cin >> caractere;
            char dest[longueur(chaine.c_str())];
            copie(dest, chaine.c_str()); 
            supprime_caractere(dest, caractere);

            cout << "la nouvelle chaine de caractere est : " << dest << "\n";

            break;
        }
        case 11 :{
            clear();
            cout << "Compte d'une nombre de mot d'une phrase\n\n";
            cout << "Entre la chaine de caractère : ";
            cin.ignore();
            getline(cin, chaine);
            cout << "Le nombre de mots est de : " << compte_mots(chaine.c_str()) <<"\n";
            break;
        }
        case 12 :{
            clear();
            hanged();
        }
    }

    return 0;
}

