#include <windows.h>//winapi o win32
#include <windowsx.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "identificadores.h"
#include <string.h>
int estado=0;
//prototico
void lector(HWND hwndButton,HWND hwndPantalla,char pantalla[50], char boton[6]);
/*  Declaracion del procedimiento de ventana  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DlgProc2(HWND, UINT, WPARAM, LPARAM);
void InsertarMenu(HWND hWnd);
////////////////////////////////////////////////////////////////////////////////
//                Win MAIN
////////////////////////////////////////////////////////////////////////////////
int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)
{
    HWND hwnd;               /* Manipulador de ventana */
    MSG mensaje;             /* Mensajes recibidos por la aplicacion */
    WNDCLASSEX wincl;        /* Estructura de datos para la clase de ventana */

    /* Estructura de la ventana */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = "NUESTRA_CLASE";
    wincl.lpfnWndProc = WindowProcedure;      /* Esta funcion es invocada por Windows */
    wincl.style = CS_DBLCLKS;                 /* Captura los doble-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Usar icono y puntero por defector */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = "Menu";
    wincl.cbClsExtra = 0;                      /* Sin informacion adicional para la */
    wincl.cbWndExtra = 0;                      /* clase o la ventana */
    /* Usar el color de fondo por defecto para la ventana */
    wincl.hbrBackground = GetSysColorBrush(COLOR_BACKGROUND);

    /* Registrar la clase de ventana, si falla, salir del programa */
    if(!RegisterClassEx(&wincl)) return 0;

    /* La clase esta registrada, crear la ventana */
    hwnd = CreateWindowEx(
           0,                   /* Posibilidades de variacion */
           "NUESTRA_CLASE",     /* Nombre de la clase */
           "Calculadora",       /* Texto del totulo */
           WS_OVERLAPPEDWINDOW, /* Tipo por defecto */
           CW_USEDEFAULT,       /* Windows decide la posicion */
           CW_USEDEFAULT,       /* donde se coloca la ventana */
           544,                 /* Ancho */
           375,                 /* Alto en pixels */
           HWND_DESKTOP,        /* La ventana es hija del escritorio */
           NULL,                /* Sin menu */
           hThisInstance,       /* Manipulador de instancia */
           NULL                 /* No hay datos de creacion de ventana */
    );

    /* Mostrar la ventana */
    InsertarMenu(hwnd);
    ShowWindow(hwnd, SW_SHOWDEFAULT);

    //MessageBox(HWND_DESKTOP, /*Manejador del estritorio*/
      //"Presiona un boton y suerte",/*Mensaje de la caja*/
      //"Saludo",/*Titulo*/
      //MB_ICONEXCLAMATION);/*tipo de caja*/
    UpdateWindow(hwnd);


    /* Bucle de mensajes, se ejecuta hasta que haya error o GetMessage devuelva FALSE */
    while(TRUE == GetMessage(&mensaje, NULL, 0, 0))
    {
        /* Traducir mensajes de teclas virtuales a mensajes de caracteres */
        TranslateMessage(&mensaje);
        /* Enviar mensaje al procedimiento de ventana */
        DispatchMessage(&mensaje);
    }

    /* Salir con valor de retorno */
    return mensaje.wParam;
}
////////////////////////////////////////////////////////////////////////////////
//                  procedimientos de ventana
////////////////////////////////////////////////////////////////////////////////

/*Esta funcion es invocada por la funcion DispatchMessage()*/
void botones(HWND hwndButton_resu,HWND hwndButton0,char pantalla[50],char boton[6],int *bandera);
void bot_opera(HWND hwndButton_resu,HWND hwndButtonNum,char pantalla[50],char boton[6], int *bandera);
void boton_ce(HWND hwndButton_resu,HWND hwndButtonNum,char pantalla[50],char boton[6]);
void bot_resultado(HWND hwndButton_resu,HWND hwndButton_ans,char pantalla[50],char boton[6],int *bandera,float *ans,float *sen,float *cose,float *tang);
void boton_ans(HWND hwndButton_resu,HWND hwndButtonNum,char pantalla[50],char boton[6], int *bandera,float *ans);
void boton_seno(HWND hwndButton_resu,HWND hwndButtonNum,char pantalla[50],char boton[6], int *bandera, float *sen);
void boton_coseno(HWND hwndButton_resu,HWND hwndButtonNum,char pantalla[50],char boton[6], int *bandera, float *cose);
void boton_tangente(HWND hwndButton_resu,HWND hwndButtonNum,char pantalla[50],char boton[6], int *bandera, float *tang);
void aux_sen(char operacion_aux,HWND hwndButton_resu, char pantalla[50], int num, int *bandera,float s);
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
      static HINSTANCE hInstance;
    static int veces;
    static HWND hwndButton1;
    static HWND hwndButton2;
    static HWND hwndButton3;
    static HWND hwndButton4;
    static HWND hwndButton5;
    static HWND hwndButton6;
    static HWND hwndButton7;
    static HWND hwndButton8;
    static HWND hwndButton9;
    static HWND hwndButton0;
    static HWND hwndButton_suma;
    static HWND hwndButton_res;
    static HWND hwndButton_mul;
    static HWND hwndButton_div;
    static HWND hwndButton_resu;
    static HWND hwndButton_c;
    static HWND hwndButton_ce;
    static HWND hwndButton_ans;
    static HWND hwndButton_sen;
    static HWND hwndButton_cose;
    static HWND hwndButton_tang;
    char pantalla[50];
    char boton[6];
    static int bandera=0;//solo tine dos estados
    static float ans;
    static float sen=0;
    static float cose=0;
    static float tang=0;
    switch (msg)                  /* manipulador del mensaje */
    {
        case WM_CREATE:
           hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
           hwndButton_resu=CreateWindowEx(0,"BUTTON","",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 10,10,175,50,hwnd,(HMENU)BTN_resultado,hInstance,NULL);
           hwndButton7=CreateWindowEx(0,"BUTTON","7",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 10,70,25,25,hwnd,(HMENU)BTN_numero_7,hInstance,NULL);
           hwndButton8=CreateWindowEx(0,"BUTTON","8",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 45,70,25,25,hwnd,(HMENU)BTN_numero_8,hInstance,NULL);
           hwndButton9=CreateWindowEx(0,"BUTTON","9",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 80,70,25,25,hwnd,(HMENU)BTN_numero_9,hInstance,NULL);
           hwndButton_div=CreateWindowEx(0,"BUTTON","/",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 115,70,25,25,hwnd,(HMENU)BTN_operacion_division,hInstance,NULL);
           hwndButton4=CreateWindowEx(0,"BUTTON","4",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 10,105,25,25,hwnd,(HMENU)BTN_numero_4,hInstance,NULL);
           hwndButton5=CreateWindowEx(0,"BUTTON","5",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 45,105,25,25,hwnd,(HMENU)BTN_numero_5,hInstance,NULL);
           hwndButton6=CreateWindowEx(0,"BUTTON","6",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 80,105,25,25,hwnd,(HMENU)BTN_numero_6,hInstance,NULL);
           hwndButton_mul=CreateWindowEx(0,"BUTTON","*",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 115,105,25,25,hwnd,(HMENU)BTN_operacion_multi,hInstance,NULL);
           hwndButton1=CreateWindowEx(0,"BUTTON","1",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 10,140,25,25,hwnd,(HMENU)BTN_numero_1,hInstance,NULL);
           hwndButton2=CreateWindowEx(0,"BUTTON","2",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 45,140,25,25,hwnd,(HMENU)BTN_numero_2,hInstance,NULL);
           hwndButton3=CreateWindowEx(0,"BUTTON","3",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 80,140,25,25,hwnd,(HMENU)BTN_numero_3,hInstance,NULL);
           hwndButton_res=CreateWindowEx(0,"BUTTON","-",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 115,140,25,25,hwnd,(HMENU)BTN_operacion_resta,hInstance,NULL);
           hwndButton0=CreateWindowEx(0,"BUTTON","0",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 45,175,25,25,hwnd,(HMENU)BTN_numero_0,hInstance,NULL);
           hwndButton_suma=CreateWindowEx(0,"BUTTON","+",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 115,175,25,25,hwnd,(HMENU)BTN_operacion_suma,hInstance,NULL);
           hwndButton_c=CreateWindowEx(0,"BUTTON","c",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 80,175,25,25,hwnd,(HMENU)BTN_c,hInstance,NULL);
           hwndButton_ce=CreateWindowEx(0,"BUTTON","ce",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 10,175,25,25,hwnd,(HMENU)BTN_ce,hInstance,NULL);
           hwndButton_ans=CreateWindowEx(0,"BUTTON","ans",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 150,175,25,25,hwnd,(HMENU)BTN_ans,hInstance,NULL);
           hwndButton_sen=CreateWindowEx(0,"BUTTON","sin",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 150,140,25,25,hwnd,(HMENU)BTN_seno,hInstance,NULL);
           hwndButton_cose=CreateWindowEx(0,"BUTTON","cos",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 150,105,25,25,hwnd,(HMENU)BTN_coseno,hInstance,NULL);
           hwndButton_tang=CreateWindowEx(0,"BUTTON","tan",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 150,70,25,25,hwnd,(HMENU)BTN_tangente,hInstance,NULL);
           return 0;
           break;
        case WM_COMMAND:
           switch(LOWORD(wParam)){
              case BTN_numero_0:
                botones(hwndButton_resu,hwndButton0,pantalla,boton,&bandera);
                break;
              case BTN_numero_1:
                botones(hwndButton_resu,hwndButton1,pantalla,boton,&bandera);
                break;
              case BTN_numero_2:
                botones(hwndButton_resu,hwndButton2,pantalla,boton,&bandera);
                break;
              case BTN_numero_3:
                botones(hwndButton_resu,hwndButton3,pantalla,boton,&bandera);
                break;
              case BTN_numero_4:
                botones(hwndButton_resu,hwndButton4,pantalla,boton,&bandera);
                break;
              case BTN_numero_5:
                botones(hwndButton_resu,hwndButton5,pantalla,boton,&bandera);
                break;
              case BTN_numero_6:
                botones(hwndButton_resu,hwndButton6,pantalla,boton,&bandera);
                break;
              case BTN_numero_7:
                botones(hwndButton_resu,hwndButton7,pantalla,boton,&bandera);
                break;
              case BTN_numero_8:
                botones(hwndButton_resu,hwndButton8,pantalla,boton,&bandera);
                break;
              case BTN_numero_9:
                botones(hwndButton_resu,hwndButton9,pantalla,boton,&bandera);
                break;
              case BTN_operacion_suma:
                bot_opera(hwndButton_resu,hwndButton_suma,pantalla,boton,&bandera);
                break;
              case BTN_operacion_resta:
                bot_opera(hwndButton_resu,hwndButton_res,pantalla,boton,&bandera);
                break;
              case BTN_operacion_multi:
                bot_opera(hwndButton_resu,hwndButton_mul,pantalla,boton,&bandera);
                break;
              case BTN_operacion_division:
                bot_opera(hwndButton_resu,hwndButton_div,pantalla,boton,&bandera);
                break;
              case BTN_resultado:
                bot_resultado(hwndButton_resu,hwndButton_ans,pantalla,boton,&bandera,&ans,&sen,&cose,&tang);
                break;
              case BTN_c:
                sprintf(pantalla,"");
                Button_SetText(hwndButton_resu,pantalla);
                break;
              case BTN_ce:
                boton_ce(hwndButton_resu,hwndButton_ce,pantalla,boton);
                break;
              case BTN_ans:
                boton_ans(hwndButton_resu,hwndButton_ans,pantalla,boton,&bandera,&ans);
                  break;
              case BTN_seno:
                boton_seno(hwndButton_resu,hwndButton_ans,pantalla,boton,&bandera,&sen);
                break;
              case BTN_coseno:
                boton_coseno(hwndButton_resu,hwndButton_ans,pantalla,boton,&bandera,&cose);
                break;
              case BTN_tangente:
                boton_tangente(hwndButton_resu,hwndButton_ans,pantalla,boton,&bandera,&tang);
                break;
              case CM_PRUEBA:
              MessageBox(hwnd, "Comando: Prueba", "Mensaje de menu", MB_OK);
              break;
              case CM_SALIR:
              MessageBox(hwnd, "Comando: Salir", "Mensaje de menu", MB_YESNO);
                 /* envía un mensaje WM_QUIT a la cola de mensajes */
                 PostQuitMessage(0);
              break;
           }
           break;

        case WM_DESTROY:
           PostQuitMessage(0);    /* envia un mensaje WM_QUIT a la cola de mensajes */
           printf("Me mori :(\n" );
           break;
        default:                  /* para los mensajes de los que no nos ocupamos */
           return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)                  /* manipulador del mensaje */
    {
        case WM_INITDIALOG:
           return TRUE;
        case WM_COMMAND:
           EndDialog(hDlg, FALSE);
           return TRUE;

    }
    return FALSE;
}
////////////////////////////////////////////////////////////////////////////////
BOOL CALLBACK DlgProc2(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    char texto[25];

    switch (msg)                  /* manipulador del mensaje */
    {
        case WM_INITDIALOG:
           sprintf(texto, "Veces invocado: %d", (int)lParam);
           SetWindowText(GetDlgItem(hDlg, TEXTO), texto);
           return TRUE;
        case WM_COMMAND:
           EndDialog(hDlg, FALSE);
           return TRUE;
    }
    return FALSE;
}
void botones(HWND hwndButton_resu,HWND hwndButtonNum,char pantalla[50],char boton[6], int *bandera){
  if(*bandera){
    *bandera=0;
    sprintf(pantalla,"");
    Button_SetText(hwndButton_resu,pantalla);
  }
  Button_GetText(hwndButton_resu,pantalla,50);
  Button_GetText(hwndButtonNum,boton,6);//se lee el manejador
  strcat(pantalla,boton);//es para concatenar
  Button_SetText(hwndButton_resu,pantalla);
}
void bot_opera(HWND hwndButton_resu,HWND hwndButtonNum,char pantalla[50],char boton[6], int *bandera){
  char operacion;
  if(*bandera){
    *bandera=0;
    sprintf(pantalla,"");
    Button_SetText(hwndButton_resu,pantalla);
  }
  Button_GetText(hwndButton_resu,pantalla,50);
  //strlen: es para dar el tamanio de la cadena
  printf("Tamanio de cadena: %d\n",strlen(pantalla));
  printf("ultimo elemento de pantalla: %c\n",pantalla[strlen(pantalla)-1] );
  operacion=pantalla[strlen(pantalla)-1];
  if(operacion=='/'||operacion=='+'||operacion=='-'||operacion=='*'){
    pantalla[strlen(pantalla)-1]='\0';
    Button_SetText(hwndButton_resu,pantalla);
  }//strcmp: es para comparar dos cadenas
  if(strcmp(pantalla,"")==0){
    sprintf(pantalla,"%d",0);
    Button_SetText(hwndButton_resu,pantalla);
  }
  Button_GetText(hwndButton_resu,pantalla,50);
  Button_GetText(hwndButtonNum,boton,6);//se lee el manejador
  strcat(pantalla,boton);//es para concatenar
  Button_SetText(hwndButton_resu,pantalla);
}
void boton_ce(HWND hwndButton_resu,HWND hwndButtonNum,char pantalla[50],char boton[6]){
  char operacion;
    Button_GetText(hwndButton_resu,pantalla,50);
    operacion=pantalla[strlen(pantalla)-1];
    if(operacion=='/'||operacion=='+'||operacion=='-'||operacion=='*'){
      pantalla[strlen(pantalla)-2]='\0';
      Button_SetText(hwndButton_resu,pantalla);
  }
  else{
    pantalla[strlen(pantalla)-1]='\0';
    Button_SetText(hwndButton_resu,pantalla);
  }
}
void bot_resultado(HWND hwndButton_resu,HWND hwndButton_ans,char pantalla[50],char boton[6],int *bandera, float *ans, float *sen,float *cose,float *tang){
  int num1,num2;
  char operacion;
  float resultado;
  int bandera_int=0;
  Button_GetText(hwndButton_resu,pantalla,50);
  printf("Valor de la operacion: %s\n",pantalla);
  for(int i=0;i<strlen(pantalla);i++){
    if(pantalla[i]=='+'||pantalla[i]=='-'||pantalla[i]=='*'||pantalla[i]=='/'){
      bandera_int=1;
      break;
    }
  }
  if(!(pantalla[strlen(pantalla)-1]=='+'||pantalla[strlen(pantalla)-1]=='-'||pantalla[strlen(pantalla)-1]=='*'||pantalla[strlen(pantalla)-1]=='/')&&bandera_int==1){
    *bandera=1;
    /*esta funcion es para capturar los valores del arreglo*/
    sscanf(pantalla,"%d%c%d",&num1,&operacion,&num2);
    printf("Valor de num1: %d\n",num1 );
    printf("Valor de num2: %d\n",num2 );
    printf("Valor de operacion: %c\n",operacion );
    switch (operacion) {
      case '+':
        resultado=num1+num2;
        break;
      case '-':
        resultado=num1-num2;
      break;
      case '*':
        resultado=num1*num2;
      break;
      case '/':
        resultado=num1/num2;
      break;
    }
    *ans=resultado;
    *sen=sin(resultado);
    *cose=cos(resultado);
    *tang=tan(resultado);
    printf("Valor de resultado: %.0f\n",resultado );
    sprintf(pantalla,"%.0f",resultado);//funciona como printf, pero imprime en la cadenas
    Button_SetText(hwndButton_resu,pantalla);
  }
}
void boton_ans(HWND hwndButton_resu,HWND hwndButtonNum,char pantalla[50],char boton[6], int *bandera, float *ans){
  char ansb[10];
  Button_GetText(hwndButton_resu,pantalla,50);
  sprintf(ansb,"%d",(int)*ans);//funciona como printf, pero imprime en la cadenas
  strcat(pantalla,ansb);//es para concatenar
  Button_SetText(hwndButton_resu,pantalla);
}
void boton_seno(HWND hwndButton_resu,HWND hwndButtonNum,char pantalla[50],char boton[6], int *bandera, float *sen){
  char senob[10];
  char operacion_aux;
  int num,num1,num2;
  char operacion;
  float s;
  int bandera_int=0;
  Button_GetText(hwndButton_resu,pantalla,50);
  printf("Tamanio de cadena: %d\n",strlen(pantalla));
  for(int i=0;i<=strlen(pantalla);i++){
    printf("%d",i );
  }
  printf("\n" );
  for(int i=0;i<strlen(pantalla);i++){
    printf("%c",pantalla[i] );
  }
  printf("_" );
  printf("\n" );
  printf("Valor de seno: %f\n",*sen);
  for(int i=0;i<strlen(pantalla);i++){
    if(pantalla[i]=='+'||pantalla[i]=='-'||pantalla[i]=='*'||pantalla[i]=='/'){
      bandera_int=1;
      break;
    }
  }
  if(!(pantalla[strlen(pantalla)-1]=='+'||pantalla[strlen(pantalla)-1]=='-'||pantalla[strlen(pantalla)-1]=='*'||pantalla[strlen(pantalla)-1]=='/')&&bandera_int==1){
    *bandera=1;
    printf("Entre al ultimo if\n" );
    sscanf(pantalla,"%d%c%d",&num1,&operacion,&num2);
    printf("Valor de num1: %d\n",num1 );
    printf("Valor de num2: %d\n",num2 );
    printf("Valor de operacion: %c\n",operacion );
    switch (operacion) {
      case '+':
        s=num1+num2;
        break;
      case '-':
        s=num1-num2;
      break;
      case '*':
        s=num1*num2;
      break;
      case '/':
        s=num1/num2;
      break;
    }
    *sen=s;
    sprintf(senob,"%f",*sen);//funciona como printf, pero imprime en la cadenas
    sprintf(pantalla,"%f",senob);//funciona como printf, pero imprime en la cadenas
    strcat(pantalla,senob);//es para concatenar
    Button_SetText(hwndButton_resu,pantalla);
  }
  operacion_aux=pantalla[strlen(pantalla)-1];
  aux_sen(operacion_aux,hwndButton_resu,pantalla, num,bandera, s);
}
void boton_coseno(HWND hwndButton_resu,HWND hwndButtonNum,char pantalla[50],char boton[6], int *bandera, float *cose){
  char cosenob[10];
  char operacion_aux;
  int num,num1,num2;
  char operacion;
  float c;
  int bandera_int=0;
  Button_GetText(hwndButton_resu,pantalla,50);
  printf("Tamanio de cadena: %d\n",strlen(pantalla));
  for(int i=0;i<=strlen(pantalla);i++){
    printf("%d",i );
  }
  printf("\n" );
  for(int i=0;i<strlen(pantalla);i++){
    printf("%c",pantalla[i] );
  }
  printf("_" );
  printf("\n" );
  printf("Valor de coseno: %f\n",*cose);
  for(int i=0;i<strlen(pantalla);i++){
    if(pantalla[i]=='+'||pantalla[i]=='-'||pantalla[i]=='*'||pantalla[i]=='/'){
      bandera_int=1;
      break;
    }
  }
  if(!(pantalla[strlen(pantalla)-1]=='+'||pantalla[strlen(pantalla)-1]=='-'||pantalla[strlen(pantalla)-1]=='*'||pantalla[strlen(pantalla)-1]=='/')&&bandera_int==1){
    *bandera=1;
    printf("Entre al ultimo if\n" );
    sscanf(pantalla,"%d%c%d",&num1,&operacion,&num2);
    printf("Valor de num1: %d\n",num1 );
    printf("Valor de num2: %d\n",num2 );
    printf("Valor de operacion: %c\n",operacion );
    switch (operacion) {
      case '+':
        c=num1+num2;
        break;
      case '-':
        c=num1-num2;
      break;
      case '*':
        c=num1*num2;
      break;
      case '/':
        c=num1/num2;
      break;
    }
    *cose=c;
    sprintf(cosenob,"%f",*cose);//funciona como printf, pero imprime en la cadenas
    sprintf(pantalla,"%f",cosenob);//funciona como printf, pero imprime en la cadenas
    strcat(pantalla,cosenob);//es para concatenar
    Button_SetText(hwndButton_resu,pantalla);
  }
  operacion_aux=pantalla[strlen(pantalla)-1];
  if(operacion_aux=='/'||operacion_aux=='+'||operacion_aux=='-'||operacion_aux=='*'){
    *bandera=1;
    pantalla[strlen(pantalla)-1]='\0';
    pantalla[strlen(pantalla)-2]='\0';
    sscanf(pantalla,"%d",&num);
    printf("Valor de num: %d\n",num );
    c=cos(num);
    printf("Valor de coseno: %f\n",c );
    sprintf(pantalla,"%f",c);//funciona como printf, pero imprime en la cadenas
    Button_SetText(hwndButton_resu,pantalla);

  }
  else {
    *bandera=1;
    sscanf(pantalla,"%d",&num);
    printf("Valor de num: %d\n",num );
    c=cos(num);
    printf("Valor de coseno: %f\n",c );
    sprintf(pantalla,"%f",c);//funciona como printf, pero imprime en la cadenas
    Button_SetText(hwndButton_resu,pantalla);
  }
}
void boton_tangente(HWND hwndButton_resu,HWND hwndButtonNum,char pantalla[50],char boton[6], int *bandera, float *tang){
  char tangenteb[10];
  char operacion_aux;
  int num,num1,num2;
  char operacion;
  float t;
  int bandera_int=0;
  Button_GetText(hwndButton_resu,pantalla,50);
  printf("Tamanio de cadena: %d\n",strlen(pantalla));
  for(int i=0;i<=strlen(pantalla);i++){
    printf("%d",i );
  }
  printf("\n" );
  for(int i=0;i<strlen(pantalla);i++){
    printf("%c",pantalla[i] );
  }
  printf("_" );
  printf("\n" );
  printf("Valor de tangente: %f\n",*tang);
  for(int i=0;i<strlen(pantalla);i++){
    if(pantalla[i]=='+'||pantalla[i]=='-'||pantalla[i]=='*'||pantalla[i]=='/'){
      bandera_int=1;
      break;
    }
  }
  if(!(pantalla[strlen(pantalla)-1]=='+'||pantalla[strlen(pantalla)-1]=='-'||pantalla[strlen(pantalla)-1]=='*'||pantalla[strlen(pantalla)-1]=='/')&&bandera_int==1){
    *bandera=1;
    printf("Entre al ultimo if\n" );
    sscanf(pantalla,"%d%c%d",&num1,&operacion,&num2);
    printf("Valor de num1: %d\n",num1 );
    printf("Valor de num2: %d\n",num2 );
    printf("Valor de operacion: %c\n",operacion );
    switch (operacion) {
      case '+':
        t=num1+num2;
        break;
      case '-':
        t=num1-num2;
      break;
      case '*':
        t=num1*num2;
      break;
      case '/':
        t=num1/num2;
      break;
    }
    *tang=t;
    sprintf(tangenteb,"%f",*tang);//funciona como printf, pero imprime en la cadenas
    sprintf(pantalla,"%f",tangenteb);//funciona como printf, pero imprime en la cadenas
    strcat(pantalla,tangenteb);//es para concatenar
    Button_SetText(hwndButton_resu,pantalla);
  }
  operacion_aux=pantalla[strlen(pantalla)-1];
  if(operacion_aux=='/'||operacion_aux=='+'||operacion_aux=='-'||operacion_aux=='*'){
    *bandera=1;
    pantalla[strlen(pantalla)-1]='\0';
    pantalla[strlen(pantalla)-2]='\0';
    sscanf(pantalla,"%d",&num);
    printf("Valor de num: %d\n",num );
    t=tan(num);
    printf("Valor de tangente: %f\n",t );
    sprintf(pantalla,"%f",t);//funciona como printf, pero imprime en la cadenas
    Button_SetText(hwndButton_resu,pantalla);

  }
  else {
    *bandera=1;
    sscanf(pantalla,"%d",&num);
    printf("Valor de num: %d\n",num );
    t=tan(num);
    printf("Valor de tangente: %f\n",t );
    sprintf(pantalla,"%f",t);//funciona como printf, pero imprime en la cadenas
    Button_SetText(hwndButton_resu,pantalla);
  }
}
void InsertarMenu(HWND hWnd){
   HMENU hMenu1, hMenu2,hMenu3, hMenu4;
   hMenu1 = CreateMenu(); /* Manipulador de la barra de menú */
   hMenu2 = CreateMenu(); /* Manipulador para el primer menú pop-up */
   hMenu4 = CreateMenu(); /* Manipulador para el primer menú pop-up */
   AppendMenu(hMenu2, MF_STRING, CM_PRUEBA, "&Prueba"); /* 1º ítem */
   AppendMenu(hMenu2, MF_SEPARATOR, 0, NULL);           /* 2º ítem (separador) */
   AppendMenu(hMenu2, MF_STRING, CM_SALIR, "&Salir");   /* 3º ítem */

   AppendMenu(hMenu4, MF_STRING, CM_PRUEBA2, "&Cientifica"); /* 1º ítem */
   AppendMenu(hMenu4, MF_SEPARATOR, 0, NULL);           /* 2º ítem (separador) */
   AppendMenu(hMenu4, MF_STRING, CM_SALIR2, "&Conversion");   /* 3º ítem */
   /* Inserción del menú pop-up */
   AppendMenu(hMenu1, MF_STRING | MF_POPUP, (UINT)hMenu2, "&Principal");
   AppendMenu(hMenu1, MF_STRING | MF_POPUP, (UINT)hMenu4, "&Segundo");
   SetMenu (hWnd, hMenu1);  /* Asigna el menú a la ventana hWnd */
}
void aux_sen(char operacion_aux,HWND hwndButton_resu, char pantalla[50], int num, int *bandera,float s){
  if(operacion_aux=='/'||operacion_aux=='+'||operacion_aux=='-'||operacion_aux=='*'){
    *bandera=1;
    pantalla[strlen(pantalla)-1]='\0';
    pantalla[strlen(pantalla)-2]='\0';
    sscanf(pantalla,"%d",&num);
    printf("Valor de num: %d\n",num );
    s=sin(num);
    printf("Valor de seno: %f\n",s );
    sprintf(pantalla,"%f",s);//funciona como printf, pero imprime en la cadenas
    Button_SetText(hwndButton_resu,pantalla);

  }
  else {
    *bandera=1;
    sscanf(pantalla,"%d",&num);
    printf("Valor de num: %d\n",num );
    s=sin(num);
    printf("Valor de seno: %f\n",s );
    sprintf(pantalla,"%f",s);//funciona como printf, pero imprime en la cadenas
    Button_SetText(hwndButton_resu,pantalla);
  }
}
//stach-guarda nuestros cambios en un area segura
//git branch <nombre-rama> <sha1-commit> -nueva rama con un commit
