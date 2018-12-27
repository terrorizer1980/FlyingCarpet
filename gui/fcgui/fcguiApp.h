/***************************************************************
 * Name:      fcguiApp.h
 * Purpose:   Defines Application Class
 * Author:    Theron Spiegl (tspiegl@gmail.com)
 * Created:   2018-12-26
 * Copyright: Theron Spiegl ()
 * License:
 **************************************************************/

#ifndef FCGUIAPP_H
#define FCGUIAPP_H

#include <wx/app.h>

class fcguiApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // FCGUIAPP_H
