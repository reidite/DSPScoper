///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MAINFRAMEUI_H__
#define __MAINFRAMEUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/dataview.h>
#include <wx/gbsizer.h>
#include <wx/scrolwin.h>
#include <wx/tglbtn.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameUI
///////////////////////////////////////////////////////////////////////////////
class MainFrameUI : public wxFrame 
{
	private:
	
	protected:
		wxScrolledWindow* m_scrolledWindow;
		wxStaticText* m_staticText_FilterOrder;
		wxChoice* m_choice_FilterOrder;
		wxStaticText* m_staticText_DesignMethod;
		wxChoice* m_choice_DesignMethod;
		wxStaticText* m_staticText_ResponseType;
		wxChoice* m_choice_ResponeType;
		wxStaticText* m_staticText_AppliedFreq;
		wxTextCtrl* m_textCtrl_AppliedFreq;
		wxDataViewListCtrl* m_dataViewListCtrl_SignalInfo;
		wxStaticText* m_staticText_SampleSize;
		wxTextCtrl* m_textCtrl_SampleSize;
		wxToggleButton* m_toggle_Start;
		wxGridSizer* gSizer_Outputs;
		
		// Virtual event handlers, overide them in your derived class
		virtual void m_choice_FilterOrderOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choice_DesignMethodOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choice_ResponeTypeOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrl_AppliedFreqOnKeyUp( wxKeyEvent& event ) { event.Skip(); }
		virtual void m_dataViewListCtrl_SignalInfoOnDataViewListCtrlItemActivated( wxDataViewEvent& event ) { event.Skip(); }
		virtual void m_dataViewListCtrl_SignalInfoOnDataViewListCtrlItemContextMenu( wxDataViewEvent& event ) { event.Skip(); }
		virtual void m_textCtrl_SampleSizeOnKeyUp( wxKeyEvent& event ) { event.Skip(); }
		virtual void m_toggle_StartOnToggleButton( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MainFrameUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 720,620 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MainFrameUI();
	
};

#endif //__MAINFRAMEUI_H__
