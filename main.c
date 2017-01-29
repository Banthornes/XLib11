#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

int main(int argc, char* argv[])
{
	Display *display;
	int screen;
	Window parentWindow;
	Window childWindow;
	XEvent event;

	display = XOpenDisplay(NULL);

	if(display == NULL)
	{
		fprintf(stderr, "Cannot open display\n");
		exit(1);
	}
	screen = DefaultScreen(display);

	/// Parent window initialization
	parentWindow = XCreateSimpleWindow(display, RootWindow(display, screen), 
		100, 100, 500, 300,
		1, BlackPixel(display, screen), WhitePixel(display, screen));

	XSelectInput(display, parentWindow, ExposureMask | KeyPressMask);
	XMapWindow(display, parentWindow);

	/// Child window initialization
	childWindow = XCreateSimpleWindow(display, parentWindow, 
		20, 20, 200, 100,
		1, BlackPixel(display, screen), WhitePixel(display, screen));
	
	XSelectInput(display, childWindow, ExposureMask | KeyPressMask);
	XMapWindow(display, childWindow);

	

	while(1)
	{
		XNextEvent(display, &event);
	}
	return 0;
}
