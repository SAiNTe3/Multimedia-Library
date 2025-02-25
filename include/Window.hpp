#pragma once
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW/glfw3native.h"
#include "Sprite.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include <chrono>
#include <thread>
typedef unsigned int uint;

class Window
{
    GLFWwindow *m_Window = nullptr;
    float r = 0;
    float g = 0;
    float b = 0;
    float a = 1;
    double m_Framerate = 0;
    bool m_Vsync = true;
    double m_LastFrameTime = 0;
    double m_TimePerFrame = 0;
    Keyboard m_Keyboard;
    Mouse m_Mouse;
    static void KeyEventCallback(GLFWwindow *window, int key, int scancode, int action, int modes);
    static void MouseEventCallback(GLFWwindow *window, int button, int action, int mods);

public:
    Window(uint width, uint height, const char *title, bool visiable = true, bool resizeable = true);
    ~Window();
    bool isOpen();
    void display();
    void clear();
    void pollEvents();
    void showWindow();
    void hideWindow();
    void setBackgroundColor(float r, float g, float b, float a);
    void setBackgroundColor(int r, int g, int b, int a);
    void setWindowSize(int width, int height);
    void getWindowSize(int &width, int &height);
    glm::vec2 getWindowSize();
    glm::dvec2 getCursorPosition();
    bool isKeyPressed(int key);
    bool isKeyReleased(int key);
    bool isMousePressed(int button);
    bool isMouseReleased(int button);
    Keyboard::KeyState getKeyState(int key);
    Mouse::MouseState getMouseState(int button);
    void setWindowPosition(int x, int y);
    void getWindowPosition(int &x, int &y);
    glm::vec2 getWindowPosition();
    void closeWindow();
    void setWindowTitle(const char *title);
    HWND getWindowHandle();
    void move(int ax, int ay);
    void setVSync(bool value);
    void setFramerateLimit(double framerate);
    void draw(Sprite &sprite);

public:
    static void Initialize(int major, int minor);
    static void Terminate();
};