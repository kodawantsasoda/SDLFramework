#include "Render.h"

//the idea is to create objects of entities out of this... example would be Entity Chicken. Then I can do stuff like Chicken.render() and what not. 

class Entity : public Render{

private:
	std::string fullPath;

	SDL_Texture* entityTexture;

public:

	Entity(std::string path);

	~Entity();

};