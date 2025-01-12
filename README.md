
<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/github_username/repo_name">
    <img src="https://i.imgur.com/n1cRrsp.png" alt="Logo" width="200" height="150">
  </a>

<h3 align="center">Autonomous Environmental Mapping and Wall Following Robot</h3>


</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

This project involves the development of a robot capable of environmental mapping and wall-following in different walled environments using simulated LiDAR sensors. Initially, the robot maps unknown environments by detecting walls and free spaces using a 360-degree ideal LiDAR sensor. After successfully mapping the boundary, the robot performs a sweep algorithm to fully map the environment's interior. The project explores the concepts of Simultaneous Localization and Mapping (SLAM), implementing both mapping and navigation algorithms in C++.

The robot navigates environments with various wall angles, including 45°, 90°, and 135°, maintaining a constant distance from walls and switching direction when necessary. The tasks are designed to apply object-oriented programming principles such as inheritance, encapsulation, and polymorphism, ensuring clean, modular code.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With

* ![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
* ![Ubuntu](https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)
* ![Visual Studio Code](https://img.shields.io/badge/Visual%20Studio%20Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white)
*  ![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

This is an example of how you may give instructions on setting up your project locally.
To get a local copy up and running, follow these simple steps.

### Prerequisites

Ubuntu or WSL (Windows Subsystem for Linux) installed.
C++ compiler (g++) installed.
Git installed for version control.

### Installation


1. Clone the repository
   ```sh
   git clone https://github.com/x/Environmental-Mapping.git
   ```
2. Go to the project directory
   ```sh
   cd Environmental=Mapping
   ```
3. Build the project using g++
   ```js
   g++ -o mapping main.cpp
   ```
4. Run the executable
   ```sh
   ./mapping
   ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

1. Mapping:
The robot begins by using the simulated LiDAR sensor to detect walls and create a map of the environment. It continuously updates its internal grid, marking cells as occupied (walls), free, or unknown.

2. Wall Following:
The robot maintains a set distance from walls and follows along their perimeter using collision detection and direction vectors.

3. Sweeping:
Once the walls are fully mapped, the robot switches to a sweeping mode, moving side-to-side while advancing incrementally to ensure complete coverage of the environment.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [ ] Implement 360-degree LiDAR sensor simulation.
- [ ] Develop a wall-following algorithm for perpendicular walls.
- [ ] Extend wall-following algorithm for angled walls (45°, 90°, 135°).
- [ ] Implement sweep algorithm for full environment mapping.


<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- CONTACT -->
## Contact

Sayf Ali Kamran sayfalikamran@gmail.com

<p align="right">(<a href="#readme-top">back to top</a>)</p>

Wall-Following
<video width="80%" height="auto" controls>
  <source src="https://github.com/user-attachments/assets/4c89cb2d-89fd-4d07-bb34-1239c4088c5c" type="video/mp4">
  Your browser does not support the video tag.
</video>
