#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <string>
#include <vector>

class Game;

class GameObject {
public:
  using Texture = int; // FIXME!
  using SFMLVector = int; // FIXME!
  using ImageNames = std::initializer_list<std::string>; // FIXME!
  using SFMLWindow = int;

  GameObject(ImageNames death, ImageNames move);

  virtual ~GameObject();

  virtual void Draw(Game& window, double round_time) = 0;

  inline const SFMLVector& GetPosition() { return position_; }

  virtual void Damage() = 0;

  inline bool IsDead() { return health_points_ <= 0; }

private:
  int health_points_;
  SFMLVector position_; // normalized position, that is, x and y ranges [0, 1]

  std::vector<Texture> death_animation_;
  std::vector<Texture> move_animation_;
};

#endif // GAMEOBJECT_HPP
