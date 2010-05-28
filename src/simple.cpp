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

   RegisterHotKey(0x5555, wxMOD_WIN, 'I');

   ListFiles();
   m_Text->LoadFile(files[m_filesList->GetSelection()]);
   m_textLine->SetFocus();
}

/*-----------------------------------------------------------------------------
 *  Event Handlers
 *-----------------------------------------------------------------------------*/
void Simple::KeyEvtHdl( wxKeyEvent& event )
{
   if (event.GetModifiers() == wxMOD_CONTROL )
   {
      switch (event.GetKeyCode())
      {
         case '/':
            {
               wxString temp;
               //temp.Printf(wxT("%d"), event.GetKeyCode());
               temp.Printf(wxT("Selection: %d\nCount: %d"), m_filesList->GetSelection(), m_filesList->GetCount());
               wxMessageBox( temp, _T("DEBUG"), wxOK);
            }
            break;

         case 'J':
            {
               int selection = m_filesList->GetSelection();
               if (wxNOT_FOUND == selection) selection = -1;

               if (selection < (int) m_filesList->GetCount())
               {
                  selection++;
                  m_filesList->SetSelection(selection);
                  m_Text->SaveFile();
                  m_Text->LoadFile(files[selection]);
               }
            }
            break;

         case 'K':
            {
               int selection = m_filesList->GetSelection();
               if (wxNOT_FOUND == selection) selection = m_filesList->GetCount();

               if (selection > 0)
               {
                  selection--;
                  m_filesList->SetSelection(selection);
                  m_Text->SaveFile();
                  m_Text->LoadFile(files[selection]);
               }
            }
            break;

         case 'O':
            {
               wxDirDialog tmpDialog(this, wxT("Select a folder"), wxFileName::FileName(files[0]).GetPath());

               if ( wxID_OK == tmpDialog.ShowModal())
               {
                  m_workingDirPicker->SetPath(tmpDialog.GetPath());
                  ListFiles();
               }
            }
            break;

         case 'I':
            m_Text->SetFocus();
            break;

         default:
            event.Skip();
            break;
      }
   }
   else
   {
      switch (event.GetKeyCode())
      {
         case WXK_ESCAPE:
            this->Iconize(true);
            break;
         default:
            event.Skip();
            break;
      }
   }
}

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
   m_Text->AppendText(m_textLine->GetValue() + wxT("\n"));
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
   wxDir(m_workingDirPicker->GetPath()).GetAllFiles(m_workingDirPicker->GetPath(), &files, wxT("*.txt"));

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
   m_filesList->SetSelection(0);
}


