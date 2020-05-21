/*
Ricardo Cuevas Mondragón

Título: Proyecto Final. C Basico.
*/

//Biliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constantes.
#define MAXMENU 3

//Prototipos de Funciones.
void titulo(void);
void limpiartablero(char gato[3][3]);
void desplegartablero(char gato[3][3]);
void desplegar_ganaste(void);
int valida_gana(char gato[3][3]);

//Funcion Principal.
int main(){

    system("color 1f");
    system("title Proyecto C Basico");
    //srand(time(NULL));

    int opcion, esc, x, y, gana, tiro;
    char xo, xocomp;
    char gato[3][3];

    do{
        system("cls");

        titulo();

        printf("\n\nMenu:");
        printf("\n1. Jugar contra la computadora.");
        printf("\n2. Jugar contra un oponente.");
        printf("\n%d. Salir.", MAXMENU);

        printf("\n\nDame una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion){

            case 1: limpiartablero(gato);
                    gana=0;
                    tiro=1;
                    esc=0;

                    //Mientras pongas otra letra que no sea x/o...
                    do{
                        printf("\nQue letra deseas ocupar? x/o: ");
                        scanf("%c", &xo);
                        getchar();

                    }while(xo!='x' && xo!='o');

                    //Mientras no hayas ganado.
                    do{
                        //Mientras la posición que des esté vacía.
                        do{
                            printf("\nDame la pos. en x: ");
                            scanf("%d", &x);
                            getchar();

                            printf("\nDame la pos. en y: ");
                            scanf("%d", &y);
                            getchar();

                        }while(gato[x][y]!='\0');

                        //Pone la letra escogida en la posicion x,y.
                        gato[x][y]=xo;
                        tiro++;

                        if(xo=='x')
                            xocomp='o';
                        else
                            xocomp='x';

                        if(tiro>9){
                            gana=valida_gana(gato);

                            //Si nadie ganó...
                            if(gana==0)
                                esc=1; //Para salirte

                        }else{
                            //Mientras la posición que de la computadora esté vacía.
                            do{
                                x=rand()%3;
                                y=rand()%3;

                            }while(gato[x][y]!='\0');

                            gato[x][y]=xocomp;
                            tiro++;
                        }

                        printf("\n");

                        desplegartablero(gato);

                        printf("\n");
                        system("pause");

                        if(tiro>5)
                            gana=valida_gana(gato);

                        printf("%d", gana);
                        system("pause");

                    }while(gana==0 && esc==0);

                    if(gana==1)
                        printf("\n\nFELICIDADES! GANASTE EL JUEGO!\n");

                    system("pause");
                    break;

            case 2: limpiartablero(gato);
                    gana=0;
                    tiro=1;
                    esc=0;

                    //Mientras pongas otra letra que no sea x/o...
                    do{
                        printf("\nJugador: 1");
                        printf("\nQue letra deseas ocupar? x/o: ");
                        scanf("%c", &xo);
                        getchar();

                    }while(xo!='x' && xo!='o');

                    //Mientras no hayas ganado.
                    do{
                        //Mientras la posición que des esté vacía.
                        do{
                            printf("\nDame la pos. en x: ");
                            scanf("%d", &x);
                            getchar();

                            printf("\nDame la pos. en y: ");
                            scanf("%d", &y);
                            getchar();

                        }while(gato[x][y]!='\0');

                        //Pone la letra escogida en la posicion x,y.
                        gato[x][y]=xo;
                        tiro++;

                        if(xo=='x')
                            xocomp='o';
                        else
                            xocomp='x';

                        if(tiro>9){
                            gana=valida_gana(gato);

                            //Si nadie ganó...
                            if(gana==0)
                                esc=1; //Para salirte

                        }else{

                            printf("\nJugador: 2");

                            //Mientras la posición que del jugador 2 esté vacía.
                            do{
                                printf("\nDame la pos. en x: ");
                                scanf("%d", &x);
                                getchar();

                                printf("\nDame la pos. en y: ");
                                scanf("%d", &y);
                                getchar();

                            }while(gato[x][y]!='\0');

                            gato[x][y]=xocomp;
                            tiro++;
                        }

                        printf("\n");

                        desplegartablero(gato);

                        printf("\n");
                        system("pause");

                        if(tiro>5){
                            gana=valida_gana(gato);
                        }

                        printf("%d", gana);
                        system("pause");

                    }while(gana==0 && esc==0);

                    if(gana==1)
                        printf("\n\nFELICIDADES! GANASTE EL JUEGO!\n");

                    system("pause");
                    break;

            case MAXMENU: printf("\nAdios %c", '\1');
                            break;

            default:
                printf("\nEscoge opciones entre 1-3\n");
                system("pause");
        }

    }while(opcion!=MAXMENU);

    return 0;
}


//Funciones.
void titulo(void)
{
    printf("\t  ,ad8888ba,                                    \n");
    printf("\t d8'    `'8b                ,d                  \n");
    printf("\td8'                          88                 \n");
    printf("\t88             ,adPPYYba,  MM88MMM  ,adPPYba,   \n");
    printf("\t88      88888  ''     `Y8    88    a8'     '8a  \n");
    printf("\tY8,        88  ,adPPPPP88    88    8b       d8  \n");
    printf("\t Y8a.    .a88  88,    ,88    88,   '8a,   ,a8'  \n");
    printf("\t  `'Y88888P'  `' 8bbdP'Y8    'Y888   `'YbbdP'   \n");

}

void limpiartablero(char gato[3][3])
{
    int x, y;

    for(y=0; y<=2; y++)
        for(x=0; x<=2; x++)
            gato[x][y]='\0';
}

void desplegartablero(char gato[3][3])
{
    int i, j;

    //Matriz en forma de gato.
    for(j=0; j<2; j++)
    {
        for(i=0; i<2; i++)
            printf("%c |", gato[i][j]);

        printf("%c", gato[2][j]);

        printf("\n");
        printf("--%c--%c--\n", '\305', '\305');
    }

    for(i=0; i<2; i++)
        printf("%c |", gato[i][j]);

    printf("%c", gato[2][j]);
}

int valida_gana(char gato[3][3])
{
    int x, y;

    x=0;
    for(y=0; y<3; y++)
    {
        if(((gato[x][y]=='x') && (gato[x+1][y]=='x') && (gato[x+2][y]=='x')) || ((gato[x][y]=='o') && (gato[x+1][y]=='o') && (gato[x+2][y]=='o')))
            return 1;
    }

    y=0;
    for(x=0; x<3; y++)
    {
        if(((gato[x][y]=='x') && (gato[x][y+1]=='x') && (gato[x][y+2]=='x')) || ((gato[x][y]=='o') && (gato[x][y+1]=='o') && (gato[x][y+2]=='o')))
            return 1;
    }

    if(((gato[0][0]=='x') && (gato[1][1]=='x') && (gato[2][2]=='x')) || ((gato[0][2]=='x') && (gato[1][1]=='x') && (gato[2][0]=='x')) || ((gato[0][0]=='o') && (gato[1][1]=='o') && (gato[2][2]=='o')))
        return 1;

    else
        return 0;

    /*
    //modo2
    if((gato[0][0]==gato[0][1]==gato[0][2]) || (gato[1][0]==gato[1][1]==gato[1][2]) || (gato[2][0]==gato[2][1]==gato[2][2]))
        return 1;

    else
    {

        if((gato[0][0]==gato[1][0]==gato[2][0]) || (gato[0][1]==gato[1][1]==gato[2][1]) || (gato[0][2]==gato[1][2]==gato[2][2]))
            return 1;

        else
        {
            if((gato[0][0]==gato[1][1]==gato[2][2]) || (gato[0][2]==gato[1][1]==gato[2][0]))
                return 1;

            else
                return 0;
        }
    }*/

    /*
    //modo1
    if(gato[0][0]==gato[0][1]==gato[0][2])
        return 1;

    else
        if(gato[1][0]==gato[1][1]==gato[1][2])
            return 1;

        else
            if(gato[2][0]==gato[2][1]==gato[2][2])
                return 1;

            else
                if(gato[0][0]==gato[1][0]==gato[2][0])
                    return 1;

                else
                    if(gato[0][1]==gato[1][1]==gato[2][1])
                        return 1;

                    else
                        if(gato[0][2]==gato[1][2]==gato[2][2])
                            return 1;

                        else
                            if(gato[0][0]==gato[1][1]==gato[2][2])
                                return 1;

                            else
                                if(gato[0][2]==gato[1][1]==gato[2][0])
                                    return 1;

                                else
                                    return 0;*/
}
