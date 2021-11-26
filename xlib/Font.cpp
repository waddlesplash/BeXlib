#include "XInnerWindow.h"
#include "GC.h"
#include <Font.h>
#include <stdlib.h>

extern "C" {
#include <X11/Xlib.h>
#include <X11/Xlcint.h>
}

int
XDrawString(Display *display, Drawable w, GC gc, int x, int y, const char* str, int len)
{
	XWindow* window = Windows::get_xwindow(w);
	window->lock();
	bex_check_gc(window, gc);
	window->DrawString(str, len, BPoint(x, y));
	window->unlock();
	return 0;
}

int
XDrawString16(Display *display, Drawable w, GC gc, int x, int y, const XChar2b* str, int len)
{
	return XDrawString(display, w, gc, x, y, (char*)str, len);
}

int
XDrawImageString(Display *display, Drawable w, GC gc, int x, int y, const char* str, int len)
{
	return XDrawString(display, w, gc, x, y, str, len);
}

void
XmbDrawString(Display *display, Drawable w, XFontSet font_set,
		GC gc, int x, int y, const char* str, int len)
{
	XDrawString(display, w, gc, x, y, str, len);
}

XFontStruct*
XLoadQueryFont(Display *display, const char *name)
{
	XFontStruct* font = new XFontStruct;
	return font;
}

int
XFreeFont(Display *dpy, XFontStruct *fs)
{
	delete fs;
	return 0;
}

XFontSet
XCreateFontSet(Display* display, _Xconst char* base_font_name_list,
	char*** missing_charset_list, int* missing_charset_count, char** def_string)
{
	return new _XOC;
}

Font
XLoadFont(Display *display, const char *name)
{
	return 0;
}

int
XSetFont(Display *display, GC gc, Font font)
{
	return 0;
}
