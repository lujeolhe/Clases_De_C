#include <windows.h>//winapi o win32
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "win004.h"
int estado=0;
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
    srand(time(NULL));

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

    MessageBox(HWND_DESKTOP, /*Manejador del estritorio*/
      "Presiona un boton y suerte",/*Mensaje de la caja*/
      "Saludo",/*Titulo*/
      MB_ICONEXCLAMATION);/*tipo de caja*/
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
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static HINSTANCE hInstance;
    static int veces;
    static int suerte;

    switch (msg)                  /* manipulador del mensaje */
    {
        case WM_CREATE:
           hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
           CreateWindowEx(0,"BUTTON","1",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 10,10,150,25,hwnd,(HMENU)BTN_EJEMPLO,hInstance,NULL);
           CreateWindowEx(0,"BUTTON","2",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 170,10,150,25,hwnd,(HMENU)BTN_EJEMPLO2,hInstance,NULL);
           CreateWindowEx(0,"BUTTON","3",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 330,10,150,25,hwnd,(HMENU)BTN_EJEMPLO3,hInstance,NULL);
           suerte=rand()%3;
           printf("Valor de suerte: %d\n",suerte );
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
              case BTN_EJEMPLO:
              if(suerte==0)
                MessageBox(HWND_DESKTOP,"Ganaste","Saludo", MB_ICONEXCLAMATION);

              else{
                MessageBox(HWND_DESKTOP,"Perdiste, suerte para la proxima","Saludo", MB_ICONSTOP);
                }
                break;
              case BTN_EJEMPLO2:
                if(suerte==1){
                  MessageBox(HWND_DESKTOP,"Ganaste","Saludo", MB_ICONEXCLAMATION);
                }
                else{
                  MessageBox(HWND_DESKTOP,"Perdiste, suerte para la proxima","Saludo", MB_ICONSTOP);
                }
                break;
                case BTN_EJEMPLO3:
                  if(suerte==2){
                    MessageBox(HWND_DESKTOP,"Ganaste","Saludo", MB_ICONEXCLAMATION);
                  }
                  else{
                    MessageBox(HWND_DESKTOP,"Perdiste, suerte para la proxima","Saludo", MB_ICONSTOP);
                  }
                  break;
           }
           suerte=rand()%3;
           printf("Valor de suerte: %d\n",suerte );
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
