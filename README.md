matrixEditor
============

Index
-----
* [Introduction](#introduction)
* [Planned features](#planned-features)
* [Known Issues](#known-issues)
* [ToDo](#todo)


Introduction
------------

MatrixEditor is a small application meant for matrixNecklace's users. With it, one can easily create matrix patterns.

At the moment, it's only possible to create a single pattern at once. When done with edition, the user can export the pattern to an hexadecimal-formatted string, meant to be used in matrixNecklace's firmware.

Bleeding edge versions can be found under the **dev** branch.


Planned features
----------------

* Timed patterns schemes
* Pre-made patterns, like letters, numbers as well as some common symbols and emojis
* Multi-platform support (Unix/Linux-based OSes, Windows, MacOS and Android)
* Easy on-the-fly programmation, using the device's screen as the transmission support

Some ideas (may not be implemented):
* An integrated compiler for the firmware
* A device uploader (flash firmware onto the chip, or simply upload patterns?)


Known Issues
------------

* 50/60 Hz differences may cause problems for screen transmission upload


ToDo
-----

* Documentation (integrated help files)
* Compiling HowTo
* Patterns ordering and timing
* Makefile instead (or in addition?) of compilation script
