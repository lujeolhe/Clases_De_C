#include <windows.h>

#define CM_PRUEBA 100
#define CM_SALIR  101

/*  Declaracion del procedimiento de ventana  */
void InsertarMenu(HWND);
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

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
    wincl.lpszMenuName = NULL;                 /* Sin menu */
    wincl.cbClsExtra = 0;                      /* Sin informacion adicional para la */
    wincl.cbWndExtra = 0;                      /* clase o la ventana */
    /* Usar el color de fondo por defecto para la ventana */
    //wincl.hbrBackground = GetSysColorBrush(COLOR_BACKGROUND);
    wincl.hbrBackground = GetSysColorBrush( GRAY_BRUSH );

    /* Registrar la clase de ventana, si falla, salir del programa */
    if(!RegisterClassEx(&wincl)) return 0;

    /* La clase est� registrada, crear la ventana */
    hwnd = CreateWindowEx(
           0,                   /* Posibilidades de variacion */
           "NUESTRA_CLASE",     /* Nombre de la clase */
           "Ejemplo 001",       /* Texto del titulo */
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


/*  Esta funcion es invocada por la funcion DispatchMessage()  */
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT mensaje, WPARAM wParam, LPARAM lParam)
{
    switch (mensaje)                  /* manipulador de mensaje */
    {
        case WM_DESTROY:
            PostQuitMessage (0);       /* Envia el mensaje WM_QUIT a la cola de mensajes */
            break;
        default:                      /* Mensajes que no queremos manejar */
            return DefWindowProc (hwnd, mensaje, wParam, lParam);
    }

    return 0;
}

void InsertarMenu(HWND hWnd)
{
   HMENU hMenu1, hMenu2;

   hMenu1 = CreateMenu(); /* Manipulador de la barra de menú */
   hMenu2 = CreateMenu(); /* Manipulador para el primer menú pop-up */
   AppendMenu(hMenu2, MF_STRING, CM_PRUEBA, "&Prueba"); /* 1º ítem */
   AppendMenu(hMenu2, MF_SEPARATOR, 0, NULL);           /* 2º ítem (separador) */
   AppendMenu(hMenu2, MF_STRING, CM_SALIR, "&Salir");   /* 3º ítem */
   /* Inserción del menú pop-up */
   AppendMenu(hMenu1, MF_STRING | MF_POPUP, (UINT)hMenu2, "&Principal");
   SetMenu (hWnd, hMenu1);  /* Asigna el menú a la ventana hWnd */
}
