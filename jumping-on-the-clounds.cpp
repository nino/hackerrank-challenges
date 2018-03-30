// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem
// Run `clang++ jumping-on-the-clouds.cpp && ./a.out`

#include <iostream>
#include <vector>

class Aerith {
private:
  std::vector<int> clouds;
  int current_cloud = 0;
  int energy = 100;
  int jump_distance;

public:
  Aerith(std::vector<int> clouds, int jump_distance);

  void jump();
  int get_current_cloud() const;
  int get_energy() const;
};

Aerith::Aerith(std::vector<int> clouds, int jump_distance)
    : clouds(clouds), jump_distance(jump_distance) {}

void Aerith::jump() {
  current_cloud = (current_cloud + jump_distance) % clouds.size();
  energy -= 1;
  if (clouds[current_cloud] == 1) {
    energy -= 2;
  }
}

int Aerith::get_current_cloud() const { return current_cloud; }
int Aerith::get_energy() const { return energy; }

int main() {
  int num_clouds;
  int jump_distance;
  std::vector<int> clouds;
  std::cin >> num_clouds >> jump_distance;
  for (int i = 0; i < num_clouds; i += 1) {
    int next_cloud;
    std::cin >> next_cloud;
    clouds.push_back(next_cloud);
  }

  Aerith aerith(clouds, jump_distance);
  do {
    aerith.jump();
  } while (aerith.get_current_cloud() != 0);
  std::cout << aerith.get_energy() << std::endl;

  return 0;
}
