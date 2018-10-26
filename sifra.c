#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
    FILE *input, *output;

    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    if(input == NULL){
        printf("error");
        return 404;
    }
    char c;
    while((c = fgetc(input))!=EOF){
        if(isdigit(c)){
            c++;
/*          if(c == ':'){
                c = '0';
            }
*/
            if(c > 57){
                c =(48-1)+(c-57);
            }
        }else if(isalpha(c)){
//begin
          /*  switch(c){
                case 'c':
                    c = 'z';
                    break;
                case 'C':
                    c = 'z';
                    break;
                case 'b':
                    c = 'y';
                    break;
                case 'B':
                    c = 'Y';
                    break;
                case 'a':
                    c = 'x';
                    break;
                case 'A':
                    c = 'X';
                    break;
                default:
                    c-=3;
                    break;
            }  */
//end                                WORKING
//----------------------------------------------------------------
//begin
            c-=3; // zmensenie znaku o 3
            int move;
            //ak je znak mensi ako 65 tak ho treba posunuť na koniec abecedy (bude to bud z, y alebo x
            if(c < 65){
                //vypocitame si ze o kolko je ten znak mensi ako hodnota pismena a, cize ak to bude napr 64
                //tak move vyjde 1 a tym padom to bude z, ak 2, tak y, a ak 3 tak x;
                move = 65 - c;
                //nastavime c na dany znak, kedze pre z vyjde hodnota vypoctu 1 tak nemozeme dat "Z" - move
                //ale musime dat z+1 - move, cize 91 - move
                c = 91 - move;
            //ak je znak v rozmedzi 91 - 96 tak je to nejaky znak mimo abecedy (moznosti su len 96,95,94 kedze
            //sifrou sa posuvalo o 3 miesta
            }else if(c>90&&c<97){
                //zase vypocitame o kolko sa ma znak posunut od konca abecedy tak ako predtym akurat ze tu
                //s hodnotou 97 -> male pismeno a
                move = 97 - c;
                //odpocitame od z+1 hodnotu move
                c = 123 - move;
            }
//end                                   WORKING
        }
        fputc(c, output);
    }
}
