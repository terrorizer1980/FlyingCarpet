/***************************************************************
 * Name:      fcguiApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Theron Spiegl (tspiegl@gmail.com)
 * Created:   2018-12-26
 * Copyright: Theron Spiegl ()
 * License:
 **************************************************************/

#include "fcguiApp.h"

//(*AppHeaders
#include "fcguiMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(fcguiApp);

bool fcguiApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	fcguiDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
