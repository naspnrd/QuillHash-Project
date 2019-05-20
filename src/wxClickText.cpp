
#include "wxClickText.h"

wxClickText::wxClickText(wxWindow *parent, wxWindowID id, const wxString &label,
                         const wxPoint& pos,
                         const wxSize& size,
                         int style, const wxString& name)
    : wxStaticText(parent, id, label, pos, size, style | wxPOPUP_WINDOW, name)
{
}

wxClickText::~wxClickText()
{
}

void wxClickText::OnMouseLeftDownEvent(wxMouseEvent& event)
{
    wxCommandEvent myevent(wxEVT_COMMAND_BUTTON_CLICKED, GetId());
    wxPostEvent(this, myevent);
    event.Skip();
}

BEGIN_EVENT_TABLE(wxClickText, wxStaticText)
    EVT_LEFT_DOWN(wxClickText::OnMouseLeftDownEvent)
END_EVENT_TABLE()
