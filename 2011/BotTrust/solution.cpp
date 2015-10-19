#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>


int solve(const std::vector<char> &robot_colors, const std::vector<int> &button_nums) {
  
  int cur_pos_O = 1;
  int cur_pos_B = 1;

  int O_free = 0;
  int B_free = 0;

  for (int i = 0; i < robot_colors.size(); i++) {
    if (robot_colors[i] == 'O') {
      int distance_to_button = std::abs(cur_pos_O - button_nums[i]);
      O_free = 1 + std::max(O_free + distance_to_button, B_free);
      cur_pos_O = button_nums[i];
    } else { 
      int distance_to_button = std::abs(cur_pos_B - button_nums[i]);
      B_free = 1 + std::max(B_free + distance_to_button, O_free);
      cur_pos_B = button_nums[i];
    }
  }
  return std::max(O_free, B_free);
}

int main() {
  int num_cases;
  std::cin >> num_cases;
  for (int case_num = 1; case_num < num_cases + 1; case_num++) {
    int num_buttons;
    std::cin >> num_buttons;
    std::vector<char> robot_colors;
    std::vector<int> button_nums;
    for (int i = 0; i < num_buttons; i++) {
      char robot_color;
      int button_num;
      std::cin >> robot_color;
      std::cin >> button_num;
      robot_colors.push_back(robot_color);
      button_nums.push_back(button_num);
    }
  std::cout << "Case #" << case_num << ": "
      << solve(robot_colors, button_nums) << std::endl;
  }
}
