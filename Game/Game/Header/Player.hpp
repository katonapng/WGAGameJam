#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.hpp"

class Player : public GameObject {
 public:

	std::vector<Texture> fire_animation_;
};


#endif  // PLAYER_HPP
