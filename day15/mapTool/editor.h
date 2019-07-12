#pragma once

//extern CHAR_INFO* pBackBuf;

void setupEditor(HANDLE hStdout);
void endEditor();
void applyEditor(HANDLE hStdout);

void changeCursorColor(int nColor);
void moveCursor(int x, int y);
void getCursorPos(int* curX, int* curY);
int getCursorAttr();
void clearScreen(int nColor);
int saveMapData(const char* fileName);
int loadMapData(const char* fileName);
WORD getTileAttribute(int x, int y);
void DrawHLine(int _cx, int _cy, int nLength, int nDir, int attr);
void DrawLine(int _cx, int _cy, int nLength, double _dy);
