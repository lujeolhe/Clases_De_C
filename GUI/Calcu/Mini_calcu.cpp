#include <windows.h>//winapi o win32
#include <windowsx.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "identificadores.h"
#include <string.h>
//Librerias para el manejo de botones
#include "Botones.hpp"
#include "AmbitoBoton.hpp"
#include "BotonNumero.hpp"
#include "BotonOperacion.hpp"
#include "BotonResultado.hpp"
#include "BotonC.hpp"
#include "BotonCE.hpp"
#include "BotonAns.hpp"
int estado=0;
//prototico
void lector(HWND hwndButton,HWND hwndPantalla,char pantalla[50], char boton[6]);
/*  Declaracion del procedimiento de ventana  */
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
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static HINSTANCE hInstance;
    static ptrBoton ptrListaBotones[20];
    switch (msg)                  /* manipulador del mensaje */
    {
        case WM_CREATE:
           hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
           char numero[3];
           for(int i=0;i<3;i++){
             sprintf(numero,"%d",7+i);
             //new crea un boton con espacio de memoria aleatorio
             ptrListaBotones[i]= new BotonNumeros(Rectangulo(25,25),numero,Punto(10+35*i,70),hwnd);

           }
           /*hwndButton_resu=CreateWindowEx(0,"BUTTON"," ",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 10,10,135,50,hwnd,(HMENU)BTN_resultado,hInstance,NULL);
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
           */
           return 0;
           break;
        case WM_COMMAND:
           switch(LOWORD(wParam)){

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
