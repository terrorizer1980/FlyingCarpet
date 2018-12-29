#include "MainFrame.h"

#include "libflyingcarpet.h"

//(*InternalHeaders(MainFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(MainFrame)
const long MainFrame::ID_RADIOBOX1 = wxNewId();
const long MainFrame::ID_RADIOBOX2 = wxNewId();
const long MainFrame::ID_BUTTON1 = wxNewId();
const long MainFrame::ID_BUTTON2 = wxNewId();
const long MainFrame::ID_TEXTCTRL1 = wxNewId();
const long MainFrame::ID_BUTTON3 = wxNewId();
const long MainFrame::ID_TEXTCTRL2 = wxNewId();
const long MainFrame::ID_GAUGE1 = wxNewId();
const long MainFrame::ID_PANEL2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MainFrame,wxFrame)
	//(*EventTable(MainFrame)
	//*)
END_EVENT_TABLE()

MainFrame::MainFrame(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(MainFrame)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(400,600));
	Panel2 = new wxPanel(this, ID_PANEL2, wxPoint(0,0), wxSize(400,600), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	wxString __wxRadioBoxChoices_1[3] =
	{
		_("Linux"),
		_("macOS"),
		_("Windows")
	};
	RadioBox1 = new wxRadioBox(Panel2, ID_RADIOBOX1, _("Step 1: Select Peer OS"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
	BoxSizer2->Add(RadioBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	wxString __wxRadioBoxChoices_2[2] =
	{
		_("Send"),
		_("Receive")
	};
	RadioBox2 = new wxRadioBox(Panel2, ID_RADIOBOX2, _("Step 2: Select Mode"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_2, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX2"));
	BoxSizer2->Add(RadioBox2, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel2, _("Step 3: Select Files or Destination Folder"));
	Button1 = new wxButton(Panel2, ID_BUTTON1, _("Select File(s)..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	StaticBoxSizer1->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(Panel2, ID_BUTTON2, _("Select Folder..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button2->Hide();
	StaticBoxSizer1->Add(Button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(Panel2, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer1->Add(TextCtrl1, 1, wxALL|wxEXPAND, 5);
	BoxSizer3->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND, 5);
	Button3 = new wxButton(Panel2, ID_BUTTON3, _("Start"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer3->Add(Button3, 0, wxALL|wxEXPAND, 5);
	OutputBox = new wxTextCtrl(Panel2, ID_TEXTCTRL2, _("Welcome to Flying Carpet!"), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer3->Add(OutputBox, 1, wxALL|wxEXPAND, 5);
	Gauge1 = new wxGauge(Panel2, ID_GAUGE1, 100, wxDefaultPosition, wxSize(-1,20), wxGA_HORIZONTAL, wxDefaultValidator, _T("ID_GAUGE1"));
	Gauge1->Hide();
	BoxSizer3->Add(Gauge1, 0, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
	Panel2->SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();
	//*)


//    Test Area
    SetupComms();
}

MainFrame::~MainFrame()
{
	//(*Destroy(MainFrame)
	//*)
}

MainFrame::Output()
{
    // TODO: listen on OutputSocket for messages

//    GoString gostr;
//    gostr = GoOutput();
//    char str[gostr.n + 1];
//    strncpy(str, gostr.p, gostr.n);
//    str[gostr.n] = '\0';
//    OutputBox->AppendText(str);
}

MainFrame::SetupComms()
{
	long long commandPort = SetupCommandListener();
	long long outputPort = SetupOutputListener();
	long long transferPort = SetupTransferListener();

	wxString s;
	s << "Go ports:\n" << commandPort << '\n' << outputPort << '\n';
    OutputBox->AppendText(s);

    wxTCPClient *client = new wxTCPClient();
    char tpstr[10];
    itoa(transferPort, tpstr, 10);
//    wxTCPConnection *tc = client->MakeConnection("127.0.0.1", tpstr, "uhhh");
//    transferConn = (wxTCPConnection*) client->MakeConnection("127.0.0.1", tpstr, "uhhh");
}

MainFrame::SendInput()
{

}
