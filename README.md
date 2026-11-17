Smooth Vanilla Doors

Animated vanilla doors and trapdoors for Minecraft Bedrock Edition Android.

Smooth Vanilla Doors is an experimental native modification for LeviLauncher, targeting Minecraft Bedrock 1.26.621.

Project objective

The objective is to investigate and implement smooth animations for the original Minecraft doors and trapdoors.

The project aims to preserve:

- Original vanilla block identifiers.
- Original textures and geometry.
- Original collision and interaction behavior.
- Redstone functionality.
- Vanilla block placement and orientation.

Important: The current project is an initial native mod scaffold. Vanilla block animations have not yet been implemented.

Target platform

Component| Target
Minecraft Bedrock| 1.26.621
Platform| Android
Architecture| arm64-v8a
Launcher| LeviLauncher
Native language| C++20
Build system| CMake
Native SDK| Preloader Android

Planned features

Doors

- Smooth opening animation.
- Smooth closing animation.
- Correct hinge rotation.
- Support for all vanilla door materials.

Trapdoors

- Smooth 90-degree rotation.
- Correct orientation and pivot.
- Support for all vanilla trapdoor materials.

Animation settings

Setting| Target
Opening angle| 90 degrees
Closing angle| 90 degrees
Duration| 300 ms
Interpolation| Ease In-Out
Target frame rate| 60 FPS

These are development targets, not implemented features.

Development roadmap

1. Create and compile the native mod.
2. Verify compatibility with LeviLauncher.
3. Identify the vanilla door rendering functions.
4. Investigate safe rendering hooks for Minecraft 1.26.621.
5. Implement a proof of concept using an original oak door.
6. Extend support to all doors and trapdoors.
7. Test redstone, collisions, paired doors and multiplayer behavior.

Project structure

smooth-vanilla-doors/
├── CMakeLists.txt
├── manifest.json.in
├── scripts/
│   └── package.ps1
├── src/
│   ├── main.cpp
│   ├── config_generator.cpp
│   └── mod/
│       ├── Config.h
│       ├── Config.cpp
│       ├── MyMod.cpp
│       └── MyMod.h
└── .github/
    └── workflows/
        └── build.yml

Compilation

The project uses GitHub Actions to compile the native Android module without requiring a local computer.

The expected output is a LeviLauncher ".levipack" package.

Safety and compatibility

Native modifications can cause crashes if internal game functions or signatures change.

Always back up Minecraft worlds before testing experimental modifications.

Project status

Version: 0.1.0

Development status: Initial native scaffold.

Animation implementation: Pending.

Target Minecraft version: 1.26.621.

---

Developed by JeysonLG19.
