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
#include "BotonTrigo.hpp"
using namespace WIN32API;
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
    static ptrBoton ptrListaBotones[30];
    AmbitoBoton ambi;
    int boton_pulsado;
    char *a[]={"sin","cos","tan"};
    switch (msg)                  /* manipulador del mensaje */
    {
        case WM_CREATE:
           hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
           char numero[3];
           for(int i=0;i<3;i++){
             sprintf(numero,"%d",1+i);
             //new crea un boton con espacio de memoria aleatorio
             ptrListaBotones[i]= new BotonNumeros(Rectangulo(25,25),numero,Punto(10+35*i,85),hwnd);
             ptrListaBotones[i]->crearBoton(hwnd,hInstance);
           }
           for(int i=0;i<3;i++){
             sprintf(numero,"%d",4+i);
             //new crea un boton con espacio de memoria aleatorio
             ptrListaBotones[i+3]= new BotonNumeros(Rectangulo(25,25),numero,Punto(10+35*i,120),hwnd);
             ptrListaBotones[i+3]->crearBoton(hwnd,hInstance);
           }
           for(int i=0;i<3;i++){
             sprintf(numero,"%d",7+i);
             //new crea un boton con espacio de memoria aleatorio
             ptrListaBotones[i+6]= new BotonNumeros(Rectangulo(25,25),numero,Punto(10+35*i,155),hwnd);
             ptrListaBotones[i+6]->crearBoton(hwnd,hInstance);
           }
           ptrListaBotones[9]= new BotonResultado(Rectangulo(170,50),"",Punto(10,10),hwnd);
           ptrListaBotones[9]->crearBoton(hwnd,hInstance);
           for(int i=0;i<4;i++){
             char operacion[4]={'+','-','*','/'};
             sprintf(numero,"%c",operacion[i]);
             //new crea un boton con espacio de memoria aleatorio
             ptrListaBotones[i+10]= new BotonOperacion(Rectangulo(25,25),numero,Punto(115,85+35*i),hwnd);
             ptrListaBotones[i+10]->crearBoton(hwnd,hInstance);
           }
           ptrListaBotones[14]= new BotonNumeros(Rectangulo(25,25),"0",Punto(45,190),hwnd);
           ptrListaBotones[14]->crearBoton(hwnd,hInstance);
           ptrListaBotones[15]= new BotonCE(Rectangulo(25,25),"CE",Punto(10,190),hwnd);
           ptrListaBotones[15]->crearBoton(hwnd,hInstance);
           ptrListaBotones[16]= new BotonC(Rectangulo(25,25),"C",Punto(80,190),hwnd);
           ptrListaBotones[16]->crearBoton(hwnd,hInstance);
           ambi.set_hwndButton_resu(ptrListaBotones[9]->get_hwndButton());
           for(int i=0;i<3;i++){
             ptrListaBotones[i+17]= new BotonTrigo(Rectangulo(25,25),a[i],Punto(150,85+35*i),hwnd);
             ptrListaBotones[i+17]->crearBoton(hwnd,hInstance);
           }
           ptrListaBotones[20]= new BotonAns(Rectangulo(25,25),"ans",Punto(150,190),hwnd);
           ptrListaBotones[20]->crearBoton(hwnd,hInstance);
           return 0;
           break;
        case WM_COMMAND:
        boton_pulsado=(int)LOWORD(wParam);
           switch(LOWORD(wParam)){

           }
           for(int i=0;i<21;i++){
           if(boton_pulsado==ptrListaBotones[i]->get_id_btn()){
             printf("Encontre el boton correcto: %d\n",ptrListaBotones[i]->get_id_btn());
             printf("El boton presionado fue: %d\n",(int)LOWORD(wParam) );
             ptrListaBotones[i]->pushAction();
             }
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
//vtable error: de referencia en metodos virtuales
//investigar como crear menus y cajas de texto
//Intentar llevar a las buenas practicas el de estructurada
