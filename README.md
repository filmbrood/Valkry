![Valkry Logo](res/ValkryLogo_AlphaBG.png)

### OpenGL renderer and application framework.

#### The Rundown
Valkry is a basic OpenGL-based 2D renderer with rudimentary event handling and ImGui integration. 3D rendering, more application features, and other niceties are in the queue.
The codebase is designed to be as portable as possible, so if your platform supports OpenGL and the C++17 standard, you should be able to make it run.

#### Features So Far
- Dynamic 2D quad skipping (culling) based on camera position
- Batch 2D rendering (also with skipping)

#### Contributing
If you'd like to contribute to Valkry, feel free to clone the repository with `git clone https://github.com/filmbrood/Valkry.git`.

Valkry is primarily built and tested on Windows, originally with VS 2019, and now with Atom and MinGW. The code has been successfully built and tested on Linux systems with G++/GNU Make, albeit with a few more bugs than the former.

#### License
Valkry is governed by the MIT license, detailed in the `LICENSE` file.
