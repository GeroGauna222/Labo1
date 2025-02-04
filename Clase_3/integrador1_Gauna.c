/*Escriba un programa que se encargue de manejar el inicio de sesion de una computadora. Este debe constar de 4 opciones:
Crear usuario: pida al usuario un nombre y contrasena y los guarde en un archivo credenciales.bin .
Iniciar sesion: pida al usuario un nombre y contrasena y los compare con los guardados.
Cambiar nombre.
Cambiar contrasena.*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int menu_op ();
void ask_name();
void add_name();

//int main()
//{
//   int op=1;
//
//   while (op != 5)
//   {
//       op = menu_op();
//       if (op <= 0 || op > 5)
//       {
//               printf("\nla opcion no esta permitida\n");
//       }
//       else
//       {
//           switch (op)
//           {
//               case 1:
//                   add_name();
//                   break;
//               case 2:
//                    ask_name();
//                   break;
//               case 3:
//
//                   break;
//               case 4:
//
//                   break;
//               case 5:
//                   printf("Fin");
//                   break;
//           }
//       }
//   }
//   return 0;
//}
//
//int menu_op () {
//  int op=1;
//
//  printf ("\n1. Crear usuario");
//  printf ("\n2. Iniciar sesion");
//  printf ("\n3. Cambiar nombre");
//  printf ("\n4. Cambiar contrasena");
//  printf ("\n5. Fin");
//
//  printf ("\nEscoja una opcion:");
//  scanf ("%d", &op);
//  return op;
//}

//void ask_name() {
//    FILE *arch;
//    char name[], sname[];
//    arch = fopen("credenciales.bin", "wb");
//    if (arch == NULL)
//    {
//        perror("Error al abrir el archivo");
//        exit (1);
//    }
//    printf("\nse abrio el archivo de trabajo\n");
//
//    printf("Ingrese nombre de usuario: ");
//    scanf("%s", name);
//    printf("Ingrese contrasena: ");
//    scanf("%s", sname);
//}
//
//void add_name() {
//    FILE *arch;
//    char name[], sname[];
//    arch = fopen("credenciales.bin", "wb");
//    if (arch == NULL)
//    {
//        perror("Error al abrir el archivo");
//        exit (1);
//    }
//    printf("\nse abrio el archivo de trabajo\n");
//
//    printf("Ingrese nombre de usuario: ");
//    scanf("%s", name);
//    printf("Ingrese contrasena: ");
//    scanf("%s", sname);
//
//    if (fwrite(name,sizeof(name),1,arch) != 1)
//        {
//            perror("\nError al escribir los datos...");
//            exit(1);
//        }
//
//    if (fwrite(sname,sizeof(sname),1,arch) != 1)
//        {
//            perror("\nError al escribir los datos...");
//            exit(1);
//        }
//
//    if (fclose(arch) != 0)
//    {
//        perror("\nError al cerrar el archivo...");
//    }
//
//    printf("\nse guard� todo en el archivo");
//
//}
//
