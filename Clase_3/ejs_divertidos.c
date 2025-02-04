//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <time.h>
//
//void vocal_count();
//void num_rand_g();
//void ppt_g();
//
//int main() {
//    int op;
//    printf("*************************************\n");
//    printf("---------------Y8--------------------\n");
//    printf("*************************************\n");
//    do {
//        printf("elija un juego :\n 1) adivina el numero\n 2) piedra papel o tijera\n 3) contador de vocales\n 4) Salir\n");
//        scanf("%d", &op);
//        switch(op) {
//        case 1:
//            num_rand_g();
//            break;
//        case 2:
//            ppt_g();
//            break;
//        case 3:
//            vocal_count();
//            break;
//        case 4:
//            printf("Fin");
//            break;
//        default:
//            printf("no hay mas juegos ;(");
//            break;
//        }
//
//    } while(op!=4);
//
//    return 0;
//}
//
//void num_rand_g() {
//    int x, an=11, i=1;
//    srand(time(NULL));
//    x = rand() % 10 + 1;
//    printf("Usted debera adivinar un numero del 1 al 10, cada vez que pierda se le contara el intento\nveremos su calificacion al final del juego\n");
//
//    printf("Intento nro %d: ", i);
//    scanf("%d", &an);
//
//    while(an!=x) {
//        printf("JAJAJAJAJAJA ERROR\n");
//        i++;
//        printf("Intento nro %d: ", i);
//        scanf("%d", &an);
//    }
//    printf("TIN TIN TIN!!! acertado\nSegún tus resultados podemos decir que...");
//
//    if (i == 1) {
//        printf("SI TE DESCRIBO TE LIMITO\n");
//    }
//    else if(i>1 && i<=3) {
//        printf("Te fue muy bien. Suerte...\n");
//    }
//    else if(i>3 && i<6) {
//        printf("Totalmente promedio\n");
//    }
//    else if(i>=6 && i<8) {
//        printf("Bastante malo, hay solo 10 opciones\n");
//    }
//    else if(i>=8 && i<=10) {
//        printf("Malo malo sos\n");
//    }
//    else {
//        printf("repetiste numeros, realmente no te entiendo\n");
//    }
//}
//
//void ppt_g(){
//    int mach, ppt;
//    srand(time(NULL));
//
//    printf("1) PIEDRA \n2) PAPEL\n3) TIJERA\n");
//
//    do {
//    mach = rand() % 3 + 1;
//    printf("Piedra, papel o tijera...\n");
//    printf("YA! ");
//    scanf("%d", &ppt);
//
//    if(mach==1 && ppt==1) {
//        printf("PIEDRA | PIEDRA\n");
//        printf("clasico...\n");
//    }
//    else if(mach==2 && ppt==1) {
//        printf("PAPEL | PIEDRA\n");
//        printf("como te va a ganar el papel\n");
//    }
//    else if(mach==3 && ppt==1) {
//        printf("TIJERA | PIEDRA\n");
//        printf("ganaste paaa\n");
//    }
//    else if(mach==1 && ppt==2) {
//        printf("PIEDRA | PAPEL\n");
//        printf("ganaste paaa\n");
//    }
//    else if(mach==2 && ppt==2) {
//        printf("PAPEL | PAPEL\n");
//        printf("empate verde!\n");
//    }
//    else if(mach==3 && ppt==2) {
//        printf("TIJERA | PAPEL\n");
//        printf("perdedorrrrrrr\n");
//    }
//    else if(mach==1 && ppt==3) {
//        printf("PIEDRA | TIJERA\n");
//        printf("perdiste con la piedra...#respect\n");
//    }
//    else if(mach==1 && ppt==3) {
//        printf("PAPEL | TIJERA\n");
//        printf("ganadorrrrrr\n");
//    }
//    else if(mach==3 && ppt==3) {
//        printf("TIJERA | TIJERA\n");
//        printf("quack\n");
//    }
//    } while(mach==ppt);
//}
//
//void vocal_count(){
//    char word[100]={0};
//    int i = 0, count = 0;;
//    printf("Dame tu frase en minusculas: ");
//    fflush(stdin);
//    fgets(word, sizeof(word), stdin);
//    word[strcspn(word, "\n")] = '\0';
//
//    for(int i=0;i<100;i++) {
//        printf("%d) %c", i, word[i]);
//    }
//
//    while(word[i]!='\0'){
//        if (word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u') {
//            count++;
//    }
//    i++;
//    }
//    printf("tengo %d vocales\n", count);
//    if (count%2 == 0) {
//        printf("cantidad par\n");
//    }
//    else {
//        printf("cantidad impar\n");
//    }
//    if (count%3 == 0) {
//        printf("multiplo de 3\n");
//    }
//    else {
//        printf("no multiplo de 3\n");
//    }
//}
