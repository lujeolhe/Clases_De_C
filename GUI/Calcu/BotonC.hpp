#ifndef WIN32_BOTTONC_H
#define WIN32_BOTTONC_H

#include "AmbitoBoton.hpp"

namespace WIN32{
  class BotonC:public AmbitoBoton,public Boton{
    public:
    void pushAction(){
      sprintf(get_pantalla(),"");
      Button_SetText(get_hwndButton_resu(),get_pantalla());
    }
  };
};
#endif
