#include "simple.h"
#include "wx/panel.h"
#include "wx/menu.h"
#include "wx/dir.h"
#include "home.xpm"


Simple::Simple(const wxString& title)
       : QuickThoughtsFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 550))
{
  SetIcon(wxIcon(wxICON(home)));


 // Centre();
  //wxPanel *panel = new wxPanel(this, wxID_ANY);
  //wxMenuBar *mbar = new wxMenuBar;
  //wxMenu *menuWidget = new wxMenu;
  //menuWidget->Append(4, _T("&Otwórz\tCtrl-O"));
  //mbar->Append(menuWidget, _T("&Plik"));
  
  //SetMenuBar(mbar);
}

void Simple::MainWindowActivated( wxActivateEvent& event )
{
   event.Skip(); 
   m_Text->AppendText(m_workingDirPicker->GetPath() + "\n");
   wxDir dir(m_workingDirPicker->GetPath());
   wxArrayString files;
   dir.GetAllFiles(m_workingDirPicker->GetPath(), &files);
   m_filesList->InsertItems(files,0);
}

void Simple::AddNote( wxCommandEvent& event )
{ 
   m_Text->AppendText(m_textLine->GetValue() + "\n");
   m_textLine->Clear();
   event.Skip(); 
}

