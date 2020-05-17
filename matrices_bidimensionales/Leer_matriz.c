#include <stdio.h>
#include "operaciones_en_matrices.h"

int main(){
  int matriz[3][valor_max];
  int aux;
  for(int i=0;i<3;i++){
    for (int j = 0; j < 3; j++) {
      scanf("%d",&aux );
      if(j<2){
        scanf(",");
      }
      matriz[i][j]=aux;
    }
    if(i<2)
      scanf("\n");
  }
  imprimir_matriz(matriz,3,3);

  FILE *fp;

 	char buffer[100] = "Esto es un texto dentro del fichero.\n";
 	char lectura[100];
 	fp = fopen ( "fichero.txt", "r+" );

 	fprintf(fp, buffer);
 	fprintf(fp, "%s", "\nEsto es otro texto dentro del fichero.\n");
  f_imprimir_matriz(fp,matriz,3,3);
  rewind(fp);
  fgets(lectura,100,fp);
  printf("Se Leyó del archivo: %s\n",lectura );
  fgets(lectura,100,fp);
  printf("Se Leyó del archivo: %s\n",lectura );
 	fclose ( fp );
}
