#include <windows.h>
#include <Windowsx.h>
#include <stdio.h>
#include <conio.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
 int xPos, yPos;
 printf("Message: %d\n", message);
 switch(message)
 {
	case WM_LBUTTONDOWN:
		MessageBox(NULL, "Window Left Click!", "Yey!", MB_ICONEXCLAMATION | MB_OK);
		break;
	case WM_RBUTTONDOWN: // quit na stlacenie tlacidla mysi
		MessageBox(NULL, "Window Right Click!", "Yey!", MB_ICONEXCLAMATION | MB_OK);
	case WM_CLOSE:
		MessageBox(NULL, "Window Close!", "Yey!", MB_ICONEXCLAMATION | MB_OK);
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		printf("Key: %c\n", wParam);
		break;
	case WM_MOUSEMOVE: // zachytenie pohybu mysi
		xPos = GET_X_LPARAM(lParam);
		yPos = GET_Y_LPARAM(lParam);
		printf("Mouse move: %d, %d\n", xPos, yPos);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
 }
 return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
 MSG msg          = {0};
 WNDCLASS wc      = {0};
 wc.lpfnWndProc   = WndProc;    // Funkcia spracovania spravy
 wc.hInstance     = hInstance;
 wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
 wc.lpszClassName = "minwindowsapp";
 if( !RegisterClass(&wc) ) return 1;

 if( !CreateWindow(wc.lpszClassName,
                   "Minimal Windows Application",
                   WS_OVERLAPPEDWINDOW|WS_VISIBLE,
                   0,0,640,480,0,0,hInstance,NULL)) return 2;
  // Cyklus obsluhujuci spravy
  while( GetMessage( &msg, NULL, 0, 0 ) > 0 ) DispatchMessage( &msg );
  return 0;
}
