#include <wx/wx.h>
#include "QuickThoughtsMain.h"

class Simple : public QuickThoughtsFrame
{
public:
    Simple(const wxString& title);
		virtual void MainWindowActivated( wxActivateEvent& event );
		virtual void AddNote( wxCommandEvent& event );
};
