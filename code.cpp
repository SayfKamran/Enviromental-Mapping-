#include <cmath>
#include <iostream>
#include <random>
#include <vector>
#include <fstream>
#include <utility>

#include "utils.h"
#include "render.h"


class my_robot : public Object {
public:
    // Constructor that initializes the grid and LiDAR range
    my_robot(int width, int height, int env_width, int env_height, int lidar_range) 
        : Object(width, height, env_width, env_height), lidar_range(lidar_range) {
        grid = std::vector<std::vector<int>>(env_width, std::vector<int>(env_height, -1));
    }

    // Grid for the robot's mapping 
    std::vector<std::vector<int>> grid;

    // Define the LiDAR mapping function
    void map_with_lidar(grid_util& main_grid, int env_width, int env_height) {
        int x_c = this->x;
        int y_c = this->y;

        for (int i = std::max(0, x_c - lidar_range); i <= std::min(env_width - 1, x_c + lidar_range); ++i) {
            for (int j = std::max(0, y_c - lidar_range); j <= std::min(env_height - 1, y_c + lidar_range); ++j) {
                if ((i - x_c) * (i - x_c) + (j - y_c) * (j - y_c) <= lidar_range * lidar_range) {
                    int value = this->grid_value(main_grid, this, i, j, lidar_range);
                    if (value != -1) {
                        grid[i][j] = value;
                    }
                }
            }
        }
    }

    // Function to detect if walls are nearby
    bool is_wall_nearby(int offsetX, int offsetY) {
        int x_check = this->x + offsetX;
        int y_check = this->y + offsetY;
        if (x_check >= 0 && x_check < grid.size() && y_check >= 0 && y_check < grid[0].size()) {
            return grid[x_check][y_check] == 1;  // Assuming '1' represents a wall in the grid
        }
        return false;
    }

    // Function to follow the wall
 void follow_wall() {

    if (is_wall_nearby(-1, 0) && !is_wall_nearby(0, -1)) {
 
        this->y -= 1;
    } else if (is_wall_nearby(0, -1) && !is_wall_nearby(1, 0)) {
 
        this->x += 1;
    } else if (is_wall_nearby(1, 0) && !is_wall_nearby(0, 1)) {
    
        this->y += 1;
    } else if (is_wall_nearby(0, 1) && !is_wall_nearby(-1, 0)) {
        
        this->x -= 1;
    } else if (is_wall_nearby(-1, 0)) {
     
        this->y += 1;
    } else if (is_wall_nearby(0, -1)) {
      
        this->x += 1;
    } else if (is_wall_nearby(1, 0)) {
        
        this->y -= 1;
    } else {
      
        this->x -= 1;
    }
}

private:
    int lidar_range;  // LiDAR sensor range
};


//===== Main parameters =====
const int env_width {800}, env_height {800};        //Width and height of the environment
const int radius {10};                              //Radius of the robot's circular body
const int min_obj_size {50};                        //Maximum object dimension. Not required for lab 3
const int max_obj_size {100};                       //Maximum object dimension. Not required for lab 3
int lidar_range{50};                                //LiDAR range, radiating from center of robot

// Grid utility class
grid_util grid(env_width, env_height, min_obj_size, max_obj_size);

// Random generator
random_generator rand_gen;

// Vector of velocity commands
std::vector<std::vector<int>> robot_pos;

int main(int argc, char const *argv[])
{


    // read config file
    std::pair<std::string, bool> config = read_csv();

    // create the walls
    std::vector<Object*> walls;

    // normal perpendicular walls
    if (config.first == "environment1.csv") {
        walls = grid.create_walls(config.first);
    }
    // angled walls
    else {
        walls = grid.create_angled_walls(config.first);
    }

     

    // Instantiate my_robot with appropriate dimensions and LiDAR range
    my_robot robot(2 * radius, 2 * radius, env_width, env_height, lidar_range);
    my_robot robot_init = robot;  // Initial position of the robot

    // push the initial position onto robot_pos
    robot_pos.push_back({robot.x, robot.y});
    int limit_count = 0;

    // run the program indefinitely until robot hits the goal or an obstacle
    while (true)
    {
        limit_count++;

    

       
        std::ofstream null_stream("/dev/null");
      
        std::streambuf* original_cout = std::cout.rdbuf(); 
        std::streambuf* original_cerr = std::cerr.rdbuf(); 
        std::cout.rdbuf(null_stream.rdbuf()); 
        std::cerr.rdbuf(null_stream.rdbuf()); 


        robot.map_with_lidar(grid, env_width, env_height);

       
        std::cout.rdbuf(original_cout);
        std::cerr.rdbuf(original_cerr);

        // Follow the wall based on surrounding walls
        robot.follow_wall();
        robot_pos.push_back({robot.x, robot.y});

        if (limit_count >= 3600) {
            std::cout << "====Program terminated after 3600 iterations====" << std::endl;
            break;
        }

      
    }


    float accuracy = grid.grid_accuracy(robot.grid);
    std::cout << "Percent of walls correctly mapped: " << accuracy * 100.0 << "%" << std::endl;

    if (config.second){
        render_window(robot_pos, walls, robot_init, env_width, env_height);
    }
    render_grid(robot_init, robot_pos, robot.grid, env_width, env_height, radius, lidar_range);

    return 0;
}