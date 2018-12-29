#ifndef MAINFRAME_H
#define MAINFRAME_H

//(*Headers(MainFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/gauge.h>
#include <wx/panel.h>
#include <wx/radiobox.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
//*)

#include <wx/sckipc.h>

#include "libflyingcarpet.h"

class MainFrame: public wxFrame
{
	public:

		MainFrame(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~MainFrame();

		//(*Declarations(MainFrame)
		wxBoxSizer* BoxSizer1;
		wxBoxSizer* BoxSizer2;
		wxBoxSizer* BoxSizer3;
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxGauge* Gauge1;
		wxPanel* Panel2;
		wxRadioBox* RadioBox1;
		wxRadioBox* RadioBox2;
		wxStaticBoxSizer* StaticBoxSizer1;
		wxTextCtrl* OutputBox;
		wxTextCtrl* TextCtrl1;
		//*)

        wxTCPConnection commandConn;
        wxTCPConnection outputConn;
        wxTCPConnection *transferConn;

        char *peer;
        char *mode;
        wxArrayString fileList;
        wxString receiveDir;
        wxString password;

	protected:

		//(*Identifiers(MainFrame)
		static const long ID_RADIOBOX1;
		static const long ID_RADIOBOX2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON3;
		static const long ID_TEXTCTRL2;
		static const long ID_GAUGE1;
		static const long ID_PANEL2;
		//*)

	private:

		//(*Handlers(MainFrame)
        Output();
        SetupComms();
        ShowPassword();
        PromptPassword();
        SendInput();
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
