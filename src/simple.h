#include <wx/wx.h>
#include "QuickThoughtsMain.h"

class Simple : public QuickThoughtsFrame
{
   public:
      Simple(const wxString& title);

      virtual void MainWindowActivatedEvtHdl( wxActivateEvent& event );
		virtual void MainWindowCloseEvtHdl( wxCloseEvent& event );
      virtual void AddNoteEvtHdl( wxCommandEvent& event );
      virtual void FileSelectedEvtHdl( wxCommandEvent& event );
      virtual void ListFilesEvtHdl( wxFileDirPickerEvent& event );
		virtual void dbgButton01ClickEvtHdl( wxCommandEvent& event );
		virtual void dbgButton02ClickEvtHdl( wxCommandEvent& event );
      

   protected:
      wxArrayString files;
      void ListFiles(void);
};
