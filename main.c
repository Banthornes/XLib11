#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

int main(int argc, char* argv[])
{
	Display *display;
	int screen;
	Window window;
	XEvent event;

	display = XOpenDisplay(NULL);

	if(display == NULL)
	{
		fprintf(stderr, "Cannot open display\n");
		exit(1);
	}
	screen = DefaultScreen(display);

	window = XCreateSimpleWindow(display, RootWindow(display, screen), 
		100, 100, 500, 300,
		1, BlackPixel(display, screen), WhitePixel(display, screen));


	XSelectInput(display, window, ExposureMask | KeyPressMask);
	XMapWindow(display, window);

	while(1)
	{
		XNextEvent(display, &event);
	}
	return 0;
}
