#include "simple.h"
#include "wx/panel.h"
#include "wx/menu.h"
#include "wx/dir.h"
#include "wx/filename.h"
#include "wx/textfile.h"
#include "wx/msgdlg.h"
#include "home.xpm"



/*-----------------------------------------------------------------------------
 *  Constructor
 *-----------------------------------------------------------------------------*/
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


   ListFiles();
   m_filesList->SetSelection(0);
   m_Text->LoadFile(files[m_filesList->GetSelection()]);
}

/*-----------------------------------------------------------------------------
 *  Event Handlers
 *-----------------------------------------------------------------------------*/
void Simple::MainWindowActivatedEvtHdl( wxActivateEvent& event )
{
}

void Simple::MainWindowCloseEvtHdl( wxCloseEvent& event )
{ 
   m_Text->SaveFile();
   event.Skip();
}

void Simple::FileSelectedEvtHdl( wxCommandEvent& event )
{
   m_Text->SaveFile();
   m_Text->LoadFile(files[m_filesList->GetSelection()]);
   event.Skip(); 
}

void Simple::ListFilesEvtHdl( wxFileDirPickerEvent& event )
{
   ListFiles();
   event.Skip(); 
}

void Simple::AddNoteEvtHdl( wxCommandEvent& event )
{ 
   m_Text->AppendText(m_textLine->GetValue() + "\n");
   m_textLine->Clear();
   event.Skip(); 
}

void Simple::dbgButton01ClickEvtHdl( wxCommandEvent& event )
{
   m_filesList->Clear();
   event.Skip();
}

void Simple::dbgButton02ClickEvtHdl( wxCommandEvent& event )
{
   ///wxMessageBox( _T("DebugButton 02"), _T("DEBUG"), wxOK);
   m_Text->SaveFile();
   event.Skip();
}

/*-----------------------------------------------------------------------------
 *  Helper functinos
 *-----------------------------------------------------------------------------*/
void Simple::ListFiles(void)
{
   //wxMessageBox( _T("ListFiles called"), _T("info"), wxOK);

   m_filesList->Clear();
   files.Clear();

   //get files list
   wxDir(m_workingDirPicker->GetPath()).GetAllFiles(m_workingDirPicker->GetPath(), &files);

   //convert full paths to file names without extension.
   wxArrayString fileNames;
   wxString temp;
   for (int i =0; i< files.GetCount(); i++)
   {
      wxFileName::SplitPath(files[i], NULL, NULL, &temp, NULL);
      fileNames.Add(temp);
   }

   //add file names to list control
   m_filesList->InsertItems(fileNames,0);
}


