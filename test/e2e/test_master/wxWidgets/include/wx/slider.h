///////////////////////////////////////////////////////////////////////////////
// Name:        wx/slider.h
// Purpose:     wxSlider interface
// Author:      Vadim Zeitlin
// Modified by:
// Created:     09.02.01
// Copyright:   (c) 1996-2001 Vadim Zeitlin
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////
#ifndef _WX_SLIDER_H_BASE_
#  define _WX_SLIDER_H_BASE_
// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------
#  include "wx/defs.h"
#  if  wxUSE_SLIDER
#    include "wx/control.h"
// ----------------------------------------------------------------------------
// wxSlider flags
// ----------------------------------------------------------------------------
#    define wxSL_HORIZONTAL	wxHORIZONTAL /* 0x0004 */
#    define wxSL_VERTICAL	wxVERTICAL   /* 0x0008 */
#    define wxSL_TICKS	0x0010
#    define wxSL_AUTOTICKS	wxSL_TICKS // we don't support manual ticks
#    define wxSL_LEFT	0x0040
#    define wxSL_TOP	0x0080
#    define wxSL_RIGHT	0x0100
#    define wxSL_BOTTOM	0x0200
#    define wxSL_BOTH	0x0400
#    define wxSL_SELRANGE	0x0800
#    define wxSL_INVERSE	0x1000
#    define wxSL_MIN_MAX_LABELS	0x2000
#    define wxSL_VALUE_LABEL	0x4000
#    define wxSL_LABELS(wxSL_MIN_MAX_LABELS|wxSL_VALUE_LABEL)
WXDLLIMPEXP_CORE extern const char wxSliderNameStr[];
// ----------------------------------------------------------------------------
// wxSliderBase: define wxSlider interface
// ----------------------------------------------------------------------------
class WXDLLIMPEXP_CORE wxSliderBase : public wxControl
{
public:
    /* the ctor of the derived class should have the following form:

    wxSlider(wxWindow *parent,
             wxWindowID id,
             int value, int minValue, int maxValue,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = wxSL_HORIZONTAL,
             const wxValidator& validator = wxDefaultValidator,
             const wxString& name = wxSliderNameStr);
    */
  wxSliderBase()
  {
   }
    // get/set the current slider value (should be in range)
  virtual int GetValue() const = 0;
  virtual void SetValue(int value) = 0;
    // retrieve/change the range
  virtual void SetRange(int minValue, int maxValue) = 0;
  virtual int GetMin() const = 0;
  virtual int GetMax() const = 0;
  void SetMin(int minValue)
  { SetRange( minValue , GetMax() ) ; }
  void SetMax(int maxValue)
  { SetRange( GetMin() , maxValue ) ; }
    // the line/page size is the increment by which the slider moves when
    // cursor arrow key/page up or down are pressed (clicking the mouse is like
    // pressing PageUp/Down) and are by default set to 1 and 1/10 of the range
  virtual void SetLineSize(int lineSize) = 0;
  virtual void SetPageSize(int pageSize) = 0;
  virtual int GetLineSize() const = 0;
  virtual int GetPageSize() const = 0;
    // these methods get/set the length of the slider pointer in pixels
  virtual void SetThumbLength(int lenPixels) = 0;
  virtual int GetThumbLength() const = 0;
    // warning: most of subsequent methods are currently only implemented in
    //          wxMSW and are silently ignored on other platforms
  void SetTickFreq(int freq)
  { DoSetTickFreq(freq); }
  virtual int GetTickFreq() const
  { return 0; }
  virtual void ClearTicks()
  { }
  virtual void SetTick(int)
  { }
  virtual void ClearSel()
  { }
  virtual int GetSelEnd() const
  { return GetMin(); }
  virtual int GetSelStart() const
  { return GetMax(); }
  virtual void SetSelection(int, int)
  { }
#    if  WXWIN_COMPATIBILITY_2_8
#    endif
protected:
    // Platform-specific implementation of SetTickFreq
  virtual void DoSetTickFreq(int)
  { /* unsupported by default */ }
    // choose the default border for this window
  wxBorder GetDefaultBorder() const override
  {
    return wxBORDER_NONE;
  }
    // adjust value according to wxSL_INVERSE style
  virtual int ValueInvertOrNot(int value) const
  {
        if (HasFlag(wxSL_INVERSE))
            return (GetMax() + GetMin()) - value;
        else
            return value;
    }
  wxDECLARE_NO_COPY_CLASS(wxSliderBase);
};
// ----------------------------------------------------------------------------
// include the real class declaration
// ----------------------------------------------------------------------------
#    if  defined(__WXUNIVERSAL__)
#      include "wx/univ/slider.h"
#    elif  defined(__WXMSW__)
#      include "wx/msw/slider.h"
#    elif  defined(__WXMOTIF__)
#      include "wx/motif/slider.h"
#    elif  defined(__WXGTK20__)
#      include "wx/gtk/slider.h"
#    elif  defined(__WXGTK__)
#      include "wx/gtk1/slider.h"
#    elif  defined(__WXMAC__)
#      include "wx/osx/slider.h"
#    elif  defined(__WXQT__)
#      include "wx/qt/slider.h"
#    endif
#  endif
#endif
    // _WX_SLIDER_H_BASE_
