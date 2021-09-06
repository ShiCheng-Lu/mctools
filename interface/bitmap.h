#ifndef _BITMAP_H_
#define _BITMAP_H_

#include <windows.h>
#include <wingdi.h>

PBITMAPINFO CreateBitmapInfoStruct(HBITMAP hBmp);

void CreateBMPFile(LPTSTR pszFile, PBITMAPINFO pbi, HBITMAP hBMP, HDC hDC);

#endif
