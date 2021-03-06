#include "control.h"
#include "parameters.h"

double gScrollXOffset = 0.f;
double gScrollYOffset = 0.f;

std::vector<std::string> gDroppedPaths;

int gMouseButton = -1;		// left, middle, right, etc..
int gModifierKey = 0;		// shift, alt, control, ...
int gMouseState = GLFW_RELEASE;			// press or release

int gKey = GLFW_KEY_UNKNOWN;
int gKeyState = GLFW_RELEASE;
int gKeyScancode;
int gKeyMods;

void funcScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
	gScrollXOffset = xoffset;
	gScrollYOffset = yoffset;
}

void funcDropCallback(GLFWwindow * window, int path_count, const char * paths[])
{
	gDroppedPaths.clear();
	for (int i = 0; i < path_count; i++) {
		gDroppedPaths.push_back(std::string(paths[i]));
	}
}

void funcMouseCallback(GLFWwindow * window, int button, int action, int mods)
{
	gMouseButton = button;
	gMouseState = action;
	gModifierKey = mods;
}

void funcKeyCallback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	gKey = key;
	gKeyScancode = scancode;
	gKeyState = action;
	gKeyMods = mods;
}

