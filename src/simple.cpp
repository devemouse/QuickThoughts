#include "simple.h"
#include "wx/panel.h"
#include "wx/menu.h"
#include "home.xpm"


Simple::Simple(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150))
{
  SetIcon(wxIcon(wxICON(home)));


  Centre();
  wxPanel *panel = new wxPanel(this, wxID_ANY);
  wxMenuBar *mbar = new wxMenuBar;
  wxMenu *menuWidget = new wxMenu;
  menuWidget->Append(4, _T("&Otwórz\tCtrl-O"));
  mbar->Append(menuWidget, _T("&Plik"));
  
  SetMenuBar(mbar);
}
