typedef void* CursorRef;

typedef enum CursorType {
	AC_Arrow,
	AC_Cross,
	AC_Resize_Left,
	AC_Resize_Up,
	AC_Hand,
	AC_IBeam
} CursorType;

CursorRef CreateAppleCursor(CursorType type);
CursorRef CreateApplePixmapCursor(bool pict[32*32], bool mask[32*32], int hot[2]);
void SetAppleCursor(CursorRef cursor);
