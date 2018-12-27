/***************************************************************
 * Name:      fcguiMain.h
 * Purpose:   Defines Application Frame
 * Author:    Theron Spiegl (tspiegl@gmail.com)
 * Created:   2018-12-26
 * Copyright: Theron Spiegl ()
 * License:
 **************************************************************/

#ifndef FCGUIMAIN_H
#define FCGUIMAIN_H

//(*Headers(fcguiDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
//*)

class fcguiDialog: public wxDialog
{
    public:

        fcguiDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~fcguiDialog();

    private:

        //(*Handlers(fcguiDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(fcguiDialog)
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON2;
        //*)

        //(*Declarations(fcguiDialog)
        wxBoxSizer* BoxSizer1;
        wxBoxSizer* BoxSizer2;
        wxButton* Button1;
        wxButton* Button2;
        wxStaticLine* StaticLine1;
        wxStaticText* StaticText1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // FCGUIMAIN_H
