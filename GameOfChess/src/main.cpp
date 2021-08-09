#include <SDL.h>
#include <stdio.h>
#include <iostream>

#include "application/ApplicationImpl.h"

int main(int argc, char* argv[])
{
	ApplicationImpl app;
	app.run();

	return 0;
}