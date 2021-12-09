#include <app/Cursor.h>

extern "C" {
#include <X11/Xlib.h>
#include <X11/cursorfont.h>
}

#include "Debug.h"

extern "C" Cursor
XCreateGlyphCursor(Display *display, Font source_font, Font mask_font,
	unsigned int source_char, unsigned int mask_char,
	XColor const *foreground_color, XColor const *background_color)
{
	BCursorID shape;
	switch (source_char) {
	case XC_xterm:
		shape = B_CURSOR_ID_I_BEAM;
		break;
	case XC_watch:
		shape = B_CURSOR_ID_PROGRESS;
		break;
	case XC_cross:
	case XC_cross_reverse:
	case XC_tcross:
	case XC_crosshair:
	case XC_diamond_cross:
	case XC_circle:
	case XC_dot:
	case XC_dotbox:
	case XC_draped_box:
		shape = B_CURSOR_ID_CROSS_HAIR;
		break;
	case XC_hand1:
	case XC_hand2:
		shape = B_CURSOR_ID_FOLLOW_LINK;
		break;
	case XC_sb_h_double_arrow:
	case XC_sb_left_arrow:
	case XC_sb_right_arrow:
		shape = B_CURSOR_ID_RESIZE_EAST_WEST;
		break;
	case XC_sb_v_double_arrow:
	case XC_sb_up_arrow:
	case XC_sb_down_arrow:
	case XC_double_arrow:
		shape = B_CURSOR_ID_RESIZE_NORTH_SOUTH;
		break;
	case XC_pirate:
		shape = B_CURSOR_ID_NOT_ALLOWED;
		break;
	case XC_bottom_right_corner:
	case XC_top_left_corner:
		shape = B_CURSOR_ID_RESIZE_NORTH_WEST_SOUTH_EAST;
		break;
	case XC_fleur:
	case XC_bottom_left_corner:
	case XC_top_right_corner:
		shape = B_CURSOR_ID_RESIZE_NORTH_EAST_SOUTH_WEST;
		break;
	default:
		shape = B_CURSOR_ID_SYSTEM_DEFAULT;
		break;
	}
	return (Cursor)new BCursor(shape);
}

extern "C" Cursor
XCreatePixmapCursor(Display *display, Pixmap source, Pixmap mask,
	XColor *foreground_color, XColor *background_color,
	unsigned int x, unsigned int y)
{
	// TODO.
	UNIMPLEMENTED();
	return BadImplementation;
}

extern "C" Status
XFreeCursor(Display* display, Cursor cursor)
{
	delete (BCursor*)cursor;
	return Success;
}
