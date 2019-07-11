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
