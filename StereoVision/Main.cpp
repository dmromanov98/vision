#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <nanogui\button.h>

#include <nanogui\window.h>

#include <nanogui\nanogui.h>
#include <nanogui\imageview.h>
#include <nanogui\stb_image.h>
#include <nanogui\imagepanel.h>

#define STB_IMAGE_IMPLEMENTATION
#include <nanogui\stb_image.h>

using namespace std;
using namespace nanogui;


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

bool bvar = true;


int main()
{
	init();
	Screen *screen = nullptr;
	screen = new Screen(Vector2i(500, 700), "NanoGUI test");

	bool enabled = true;
	FormHelper *gui = new FormHelper(screen);
	Window *window = gui->addWindow(Eigen::Vector2i(10, 10), "Form helper example");
	gui->addGroup("Cameras");
	gui->addVariable("bool", bvar);

	//auto imageView = new ImageView(window, mImagesData[0].first.texture());
	//imageView->bindImage(mImagesData[i].first.texture());

	gui->addGroup("Some buttons");
	gui->addButton("A button", []() { std::cout << "Button pressed." << std::endl; });

	screen->setVisible(true);
	screen->performLayout();
	window->center();

	nanogui::mainloop();

	return 0;
}