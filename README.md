# **7-Segment Display Simulation**

## **Overview**
This project simulates a 7-segment digital display using OpenGL. The application cycles through different patterns by toggling specific segments of the display, demonstrating basic OpenGL rendering and animation techniques.

---

## **Features**
- **Real-time Animation**: Simulates segment transitions in a dynamic display.
- **OpenGL Graphics**: Uses GLUT for window management and rendering.

---

## **Prerequisites**
- OpenGL, GLU, and GLUT libraries.
- C++ compiler supporting OpenGL (g++ recommended).

---

## **Build and Run**
1. Compile the program:
```bash
g++ -o my_program main.cpp segment.cpp -lGL -lGLU -lglut
```

2. Run the program:
```bash
./my_program
```