#include <windows.h>//winapi o win32
#include <windowsx.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "identificadores.h"
#include <string.h>
int estado=0;
//prototico
void lector(HWND hwndButton,HWND hwndPantalla,char pantalla[50], char boton[6]);
/*  Declaraci�n del procedimiento de ventana  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DlgProc2(HWND, UINT, WPARAM, LPARAM);
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

    /* La clase est� registrada, crear la ventana */
    hwnd = CreateWindowEx(
           0,                   /* Posibilidades de variacion */
           "NUESTRA_CLASE",     /* Nombre de la clase */
           "Volado",       /* Texto del totulo */
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

/*  Esta funcion es invocada por la funcion DispatchMessage()  */
void botones(HWND hwndButton_resu,HWND hwndButton0,char pantalla[50],char boton[6]);
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
    char pantalla[50];
    char boton[6];
    switch (msg)                  /* manipulador del mensaje */
    {
        case WM_CREATE:
           hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
           hwndButton_resu=CreateWindowEx(0,"BUTTON"," ",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 10,10,135,50,hwnd,(HMENU)BTN_resultado,hInstance,NULL);
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
           return 0;
           break;
        case WM_COMMAND:
           switch(LOWORD(wParam)) {
              case CM_DIALOGO:
                 DialogBox(hInstance, "DialogoPrueba", hwnd, DlgProc);
                 break;
              case CM_DIALOGO2:
                 veces++;
                 DialogBoxParam(hInstance, "DialogoPrueba", hwnd, DlgProc2, veces);
                 break;
              case BTN_numero_0:
              botones(hwndButton_resu,hwndButton0,pantalla,boton);
                  /*Button_GetText(hwndButton_resu,pantalla,50);
                  Button_GetText(hwndButton0,boton,6);//se lee el manejador
                  strcat(pantalla,boton);
                  Button_SetText(hwndButton_resu,pantalla);*/
                break;
                //tarea meter esto en una funcion, generalizarla
                case BTN_numero_1:
                botones(hwndButton_resu,hwndButton1,pantalla,boton);
                break;
                case BTN_numero_2:
                botones(hwndButton_resu,hwndButton2,pantalla,boton);
                break;
                case BTN_numero_3:
                botones(hwndButton_resu,hwndButton3,pantalla,boton);
                break;
                case BTN_numero_4:
                botones(hwndButton_resu,hwndButton4,pantalla,boton);
                break;
                case BTN_numero_5:
                botones(hwndButton_resu,hwndButton5,pantalla,boton);
                break;
                case BTN_numero_6:
                botones(hwndButton_resu,hwndButton6,pantalla,boton);
                break;
                case BTN_numero_7:
                botones(hwndButton_resu,hwndButton7,pantalla,boton);
                break;
                case BTN_numero_8:
                botones(hwndButton_resu,hwndButton8,pantalla,boton);
                break;
                case BTN_numero_9:
                botones(hwndButton_resu,hwndButton9,pantalla,boton);
                break;
                case BTN_operacion_suma:
                botones(hwndButton_resu,hwndButton_suma,pantalla,boton);
                break;
                case BTN_operacion_resta:
                botones(hwndButton_resu,hwndButton_res,pantalla,boton);
                break;
                case BTN_operacion_multi:
                botones(hwndButton_resu,hwndButton_mul,pantalla,boton);
                break;
                case BTN_operacion_division:
                botones(hwndButton_resu,hwndButton_div,pantalla,boton);
                break;
           }
           break;
        case WM_DESTROY:
           PostQuitMessage(0);    /* envoa un mensaje WM_QUIT a la cola de mensajes */
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
void botones(HWND hwndButton_resu,HWND hwndButtonNum,char pantalla[50],char boton[6]){
  Button_GetText(hwndButton_resu,pantalla,50);
  Button_GetText(hwndButtonNum,boton,6);//se lee el manejador
  strcat(pantalla,boton);
  Button_SetText(hwndButton_resu,pantalla);
}
