#include <windows.h>//winapi o win32
#include <windowsx.h>
#include <stdio.h>

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
    MSG mensaje;             /* Mensajes recibidos por la aplicaci�n */
    WNDCLASSEX wincl;        /* Estructura de datos para la clase de ventana */


    /* Estructura de la ventana */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = "NUESTRA_CLASE";
    wincl.lpfnWndProc = WindowProcedure;      /* Esta funci�n es invocada por Windows */
    wincl.style = CS_DBLCLKS;                 /* Captura los doble-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Usar icono y puntero por defector */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = "Menu";
    wincl.cbClsExtra = 0;                      /* Sin informaci�n adicional para la */
    wincl.cbWndExtra = 0;                      /* clase o la ventana */
    /* Usar el color de fondo por defecto para la ventana */
    wincl.hbrBackground = GetSysColorBrush(COLOR_BACKGROUND);

    /* Registrar la clase de ventana, si falla, salir del programa */
    if(!RegisterClassEx(&wincl)) return 0;

    /* La clase est� registrada, crear la ventana */
    hwnd = CreateWindowEx(
           0,                   /* Posibilidades de variaci�n */
           "NUESTRA_CLASE",     /* Nombre de la clase */
           "Ejemplo 004",       /* Texto del t�tulo */
           WS_OVERLAPPEDWINDOW, /* Tipo por defecto */
           CW_USEDEFAULT,       /* Windows decide la posici�n */
           CW_USEDEFAULT,       /* donde se coloca la ventana */
           544,                 /* Ancho */
           375,                 /* Alto en pixels */
           HWND_DESKTOP,        /* La ventana es hija del escritorio */
           NULL,                /* Sin men� */
           hThisInstance,       /* Manipulador de instancia */
           NULL                 /* No hay datos de creaci�n de ventana */
    );

    //ocultar la ventana de consola
    //ShowWindow (GetConsoleWindow(), SW_HIDE);
    /* Mostrar la ventana */
    ShowWindow(hwnd, SW_SHOWDEFAULT);
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

/*  Esta funci�n es invocada por la funci�n DispatchMessage()  */
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static HINSTANCE hInstance;
    static int veces;
    static HWND hwndButton1;
    static HWND hwndButton2;
    static HWND hwndButton3;
    static HWND hwndButton4;
    char buffer[20];
    int numero;
    int suma=0;
    char operacion;
    switch (msg)                  /* manipulador del mensaje */
    {
        case WM_CREATE:
           hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
           hwndButton1=CreateWindowEx(0,"BUTTON","1",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 10,10,150,25,hwnd,(HMENU)BTN_EJEMPLO,hInstance,NULL);
           hwndButton2=CreateWindowEx(0,"BUTTON","2",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 10,45,150,25,hwnd,(HMENU)BTN_EJEMPLO2,hInstance,NULL);
           hwndButton3=CreateWindowEx(0,"BUTTON","0",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 10,80,150,25,hwnd,(HMENU)BTN_EJEMPLO3,hInstance,NULL);
           hwndButton4=CreateWindowEx(0,"BUTTON","+",BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, 180,10,150,25,hwnd,(HMENU)BTN_EJEMPLO4,hInstance,NULL);
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
                    //MessageBox(HWND_DESKTOP,"Hola Mundo","Saludo", MB_OK);

                    Button_GetText(hwndButton1,/*manejador del boton*/
                                    buffer,    /*buffer donde se va a guardar el texto*/
                                    20);       /*tamanio max del buffer*/
                    numero=atoi(buffer);
                    numero++;
                    printf("El texto es: %s\n",buffer );
                    sprintf(buffer,"%d",numero);
                    Button_SetText(hwndButton1,buffer);
                    estado=1;
                    break;
              case BTN_EJEMPLO2:
                    //MessageBox(HWND_DESKTOP,"Hola Mundo","Saludo", MB_OK);

                    Button_GetText(hwndButton2,/*manejador del boton*/
                                    buffer,    /*buffer donde se va a guardar el texto*/
                                    20);       /*tamanio max del buffer*/
                    numero=atoi(buffer);
                    numero--;
                    printf("El texto es: %s\n",buffer );
                    sprintf(buffer,"%d",numero);
                    Button_SetText(hwndButton2,buffer);


                break;
              case BTN_EJEMPLO3:
                    Button_GetText(hwndButton4,/*manejador del boton*/
                              buffer,    /*buffer donde se va a guardar el texto*/
                              20);
                    operacion=buffer[0];
                    Button_GetText(hwndButton1,/*manejador del boton*/
                              buffer,    /*buffer donde se va a guardar el texto*/
                              20);
                    numero=atoi(buffer);
                    suma=numero;

                    Button_GetText(hwndButton2,/*manejador del boton*/
                              buffer,    /*buffer donde se va a guardar el texto*/
                              20);
                    numero=atoi(buffer);
                    if(operacion=='+'){
                      suma=suma+numero;
                    }
                    else
                      suma=suma*numero;

                    sprintf(buffer,"%d",suma);
                    Button_SetText(hwndButton3,buffer);
                    break;
              case BTN_EJEMPLO4:
                    Button_GetText(hwndButton4,/*manejador del boton*/
                        buffer,    /*buffer donde se va a guardar el texto*/
                        20);
                    if(buffer[0]=='+'){
                      Button_SetText(hwndButton4,"*");
                    }
                    else{
                      Button_SetText(hwndButton4,"+");
                    }

           }
           break;
        case WM_DESTROY:
           PostQuitMessage(0);    /* env�a un mensaje WM_QUIT a la cola de mensajes */
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
