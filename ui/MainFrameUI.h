///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __NONAME_H__
#define __NONAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/radiobut.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
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
	wxRadioButton* m_radioBtn_IIR;
	wxRadioButton* m_radioBtn_FIR;
	wxRadioButton* m_radioBtn_Firstorder;
	wxRadioButton* m_radioBtn_Secondorder;
	wxRadioButton* m_radioBtn_Lowpass;
	wxRadioButton* m_radioBtn_Highpass;
	wxRadioButton* m_radioBtn_Bandpass;
	wxRadioButton* m_radioBtn_Bandstop;
	wxStaticText* m_staticText_Samplefreq;
	wxTextCtrl* m_textCtrl_Samplefreq;
	wxStaticText* m_staticText_Passfreq;
	wxTextCtrl* m_textCtrl_Passfreq;
	wxStaticText* m_staticText_Stopfreq;
	wxTextCtrl* m_textCtrl_Stopfreq;
	wxToggleButton* m_toggle_Start;
	wxGridSizer* gSizer_Outputs;

	// Virtual event handlers, overide them in your derived class
	virtual void m_radioBtn_IIROnRadioButton(wxCommandEvent& event) { event.Skip(); }
	virtual void m_radioBtn_FIROnRadioButton(wxCommandEvent& event) { event.Skip(); }
	virtual void m_radioBtn_FirstorderOnRadioButton(wxCommandEvent& event) { event.Skip(); }
	virtual void m_radioBtn_SecondorderOnRadioButton(wxCommandEvent& event) { event.Skip(); }
	virtual void m_radioBtn_LowpassOnRadioButton(wxCommandEvent& event) { event.Skip(); }
	virtual void m_radioBtn_HighpassOnRadioButton(wxCommandEvent& event) { event.Skip(); }
	virtual void m_radioBtn_BandpassOnRadioButton(wxCommandEvent& event) { event.Skip(); }
	virtual void m_radioBtn_BandstopOnRadioButton(wxCommandEvent& event) { event.Skip(); }
	virtual void m_textCtrl_SamplefreqOnKeyUp(wxKeyEvent& event) { event.Skip(); }
	virtual void m_textCtrl_PassfreqOnKeyUp(wxKeyEvent& event) { event.Skip(); }
	virtual void m_textCtrl_StopfreqOnKeyUp(wxKeyEvent& event) { event.Skip(); }
	virtual void m_toggle_StartOnToggleButton(wxCommandEvent& event) { event.Skip(); }


public:

	MainFrameUI(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(910, 437), long style = wxDEFAULT_FRAME_STYLE | wxFRAME_TOOL_WINDOW | wxTAB_TRAVERSAL);

	~MainFrameUI();

};

#endif //__NONAME_H__
