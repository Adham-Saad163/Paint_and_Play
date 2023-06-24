# Paint & Play

Paint & Play is a C++ application built using object-oriented programming as part of Zewail City University of Science and Technology's course Fundamentals of Computer Programming (OOP C++). The application allows users to draw shapes and play simple games with those shapes. Users can draw various shapes, fill them with different colors, edit them, save and load a graph of shapes, and more.

## Overview
The application supports two modes of operation: DRAW mode (startup mode) and PLAY mode. The DRAW mode includes features such as drawing shapes, changing pen color, filling color, sticking images to shapes, and more. The PLAY mode includes features such as hiding the graph, starting a game, and more. The graphical user interface (GUI) integrates an open-source graphics library (Carnegie Mellon University graphics Library) to handle the GUI easily.


## Program Classes 
To implement the functionality, the program has five main classes:

1. GUI Class
2. Controller Class
3. Shape Class
4. Graph Class
5. Operations Class

The GUI Class is responsible for interacting with the user, while the Controller Class controls everything in the application. The Shape Class is the base class for all types of shapes, and the Graph Class holds all shapes in the system. The Operation Class is the base class for all types of operations to be supported by the application.

### GUI Class
The GUI Class is responsible for interacting with the user. All user inputs, program outputs, and graph drawings are done through this class. If any other class wants to read/display anything to the user, it must call a member function of this class.

### Controller Class
The Controller Class is the maestro class that controls everything in the application. It has a list of all shapes and a pointer to a GUI object. The job of this class is to manage other classes, not to do their jobs. Therefore, it just instructs other classes to do their jobs.

### Shape Class
The Shape Class is the base class for all types of shapes (lines, rectangles, etc.). To add a new shape (a square, for example), we must inherit the shape from this class. Then we override its virtual functions.

### Graph Class
The Graph Class is used to hold all shapes in the system. It stores shapes in a C++ vector. Any operation on the shapes (e.g. adding, delete, resizing, coloring) MUST be done through member functions of this class.

### Operations Class
The Operations Class is the base class for all types of operations to be supported by the application. To add a new operation (Save operation, for example), we must inherit from this class. Then we override its virtual functions.


To use the application, users need to follow a general flow of operations, which includes getting the user operation type, creating a suitable operation object for that input, executing the operation, and reflecting the operation on the interface.

## Features
The application supports two modes of operation: DRAW mode & PLAY mode.

### DRAW Mode
The DRAW mode includes the following features:

* Draw Shapes [Line, Triangle, Square, Circle, Regular Polygon, Irregular Polygon]
* Change [Pen Color, Fill Color]
* Stick an Image to a Shape
* Draw Color Palette
* Delete a Single Shape
* Switch to PLAY Mode
* Save the Graph to a File
* Load the Graph from a File
* Resize a Single Shape
* Rotate a Single Shape
* Move a Single Shape by dragging
* Copy a Single Shape
* Cut a Single Shape
* Paste a Single Shape
* Undo/ Redo
* Zoom in
* Zoom out
* Multi delete
* Duplicate Graph
* Scramble Graph
* Exit the Application


### PLAY Mode
The PLAY mode includes the following features:

* Hide Graph
* Unhide Graph
* Start Game (This feature uses the following features: Duplicate, Scramble, Hide, Unhide)

## Considerations
During the implementation of this project, we have taken the following considerations into account:

* Memory Management
* Object-Oriented Concepts (Modularity, Maintainability, and Class Responsibilities)
* Polymorphism & Class Responsibilities

## Getting Started
To use this project, follow these steps:

1. Clone the repository: `https://github.com/Adham-Saad163/Paint_and_Play.git`
2. Compile the code using a C++ compiler of your choice (MinGW for example).
3. Run the executable file.

You can find the project repository [here](https://github.com/Adham-Saad163/Paint_and_Play.git).


## Contributing
Contributions to Paint & Play are always welcome. If you want to contribute to the project, please follow these steps:

1. Fork this repository.
2. Create a new branch for your feature/bug fix.
3. Make changes to your forked repository.
4. Test your changes.
5. Submit a pull request to this repository.
5. Wait for your changes to be reviewed and merged.

Please make sure to follow the code style of the project and write clear commit messages. And if possible, please add unit tests for your changes.

## Contact
If you have any questions, suggestions, or concerns regarding this project, please feel free to contact us:

* Adham Saad: s-adham.saad@zewailcity.edu.eg
* Mohamed Morshedy: s-mohamed.morshedy@zewailcity.edu.eg
* Mahmoud Elshahed: s-mahmoud.elshahed@zewailcity.edu.eg
  
Thank you for your interest and support!
