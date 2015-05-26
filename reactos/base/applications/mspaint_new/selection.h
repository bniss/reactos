/*
 * PROJECT:     PAINT for ReactOS
 * LICENSE:     LGPL
 * FILE:        base/applications/mspaint_new/selection.h
 * PURPOSE:     Window procedure of the selection window
 * PROGRAMMERS: Benedikt Freisen
 */

void RegisterWclSelection();

void ForceRefreshSelectionContents();

LRESULT CALLBACK SelectionWinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);