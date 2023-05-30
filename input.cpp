#include "input.h"
#include <GLFW/glfw3.h>

bool Input::KeyIsPressed(int key) {
    int state = glfwGetKey(glfwGetCurrentContext(), key);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}
