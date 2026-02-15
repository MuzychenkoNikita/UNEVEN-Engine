# UNEVEN-Engine

<img src="logo-big.png" width="1000" />

UNEVEN Engine is non-comercial open-source project made for self-educational purpose about modern game engines develpment. Everybody is welcome to use and contribute to this project. Project is based on C++ 11 and several libraries for simplifying OpenGL 3.3 function calls. All dependencies required for project are already included, no need for additional istalation. There is a support for major OS platforms Windows, MacOS and Linux.

# About Jira
<img src="https://media.licdn.com/dms/image/v2/D4D12AQFG6GdFfKPR5w/article-cover_image-shrink_600_2000/article-cover_image-shrink_600_2000/0/1711685209128?e=2147483647&v=beta&t=CKTpNqZcI1iA633XTgb-CCotcc1odqOLWrGq7mzQiqo" width="1000" />

[Jira Page](https://uneven.atlassian.net/jira/software/projects/UNEVEN/summary)

This project uses Jira prduct for monitoring development workflow. Any tasks, features and issue you see can be found on project's jira page by typing [KEY-N] it refers to. 

# How to use
Scripts for relevant platforms are provided within a `Scripts/` directory to setup project using premake5.
- Windows: open `Scripts/` and run `Setup-Windows.bat`, then open generated Visual Studio solution in root directory `UNEVEN-Engine/`
- MacOs: open `Scripts/` with terminal and run `sh Setup-Mac.sh`. If you getting permission errors, you have to give permission for scrpits by typing next two commands `chmod +x ../Vendor/Binaries/Premake/macOS/premake5` and `chmod +x Setup-Mac.sh`. After that Xcode solution will be generated in root directory `UNEVEN-Engine/`
- Linux: within 'Scripts/' directory run `chmod +x script.sh && ./script.sh`.

# License
- UNLICENSE for this repository (see `UNLICENSE.txt` for more details)
- Premake is licensed under BSD 3-Clause (see included LICENSE.txt file for more details)
