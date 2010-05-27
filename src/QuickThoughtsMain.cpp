///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "QuickThoughtsMain.h"

///////////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE( QuickThoughtsFrame, wxFrame )
	EVT_ACTIVATE( QuickThoughtsFrame::_wxFB_MainWindowActivatedEvtHdl )
	EVT_CLOSE( QuickThoughtsFrame::_wxFB_MainWindowCloseEvtHdl )
	EVT_LISTBOX( ID_FILES_LIST, QuickThoughtsFrame::_wxFB_FileSelectedEvtHdl )
	EVT_DIRPICKER_CHANGED( ID_DIR_PICKER, QuickThoughtsFrame::_wxFB_ListFilesEvtHdl )
	EVT_BUTTON( ID_ADD_BUTTON, QuickThoughtsFrame::_wxFB_AddNoteEvtHdl )
	EVT_BUTTON( ID_DBG_BUTTON_01, QuickThoughtsFrame::_wxFB_dbgButton01ClickEvtHdl )
	EVT_BUTTON( ID_DBG_BUTTON_01, QuickThoughtsFrame::_wxFB_dbgButton02ClickEvtHdl )
END_EVENT_TABLE()

QuickThoughtsFrame::QuickThoughtsFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	m_filesList = new wxListBox( this, ID_FILES_LIST, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT ); 
	bSizer1->Add( m_filesList, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_workingDirPicker = new wxDirPickerCtrl( this, ID_DIR_PICKER, wxT("../tmpcfg/"), wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	bSizer3->Add( m_workingDirPicker, 0, wxALL|wxEXPAND, 5 );
	
	m_Text = new wxRichTextCtrl( this, ID_TEXT_BOX, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0|wxHSCROLL|wxSIMPLE_BORDER|wxVSCROLL|wxWANTS_CHARS );
	bSizer3->Add( m_Text, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textLine = new wxTextCtrl( this, ID_TEXT_LINE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxSIMPLE_BORDER );
	bSizer2->Add( m_textLine, 1, wxALL|wxEXPAND, 5 );
	
	m_addButton = new wxButton( this, ID_ADD_BUTTON, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	m_addButton->SetDefault(); 
	bSizer2->Add( m_addButton, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	bSizer3->Add( bSizer2, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_dbgButton01 = new wxButton( this, ID_DBG_BUTTON_01, wxT("m_dbgButton01"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_dbgButton01, 0, wxALL, 5 );
	
	m_dbgButton02 = new wxButton( this, ID_DBG_BUTTON_01, wxT("m_dbgButton02"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_dbgButton02, 0, wxALL, 5 );
	
	bSizer3->Add( bSizer4, 0, wxEXPAND, 5 );
	
	bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
}

QuickThoughtsFrame::~QuickThoughtsFrame()
{
}
