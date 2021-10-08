#ifndef COMMON_TO_ENTITIES_H
#define COMMON_TO_ENTITIES_H


//It is a class which will contain the attributes which are common to all the entities. 
//It also contains the related utilites.
// You can consider is as a parent class to all the entities.
//
class CommonToEntities
{
protected:
	const int collisionBoxHeight;
	const int collisionBoxWidth;
	const int movementSpeed;
public:

	//Constructor which uses initializers list.
	//It also acts as a default constructor as deafult values for all the variables are present.
	CommonToEntities(int collisionBoxHeight=10, int collisionBoxWidth=10, int movementSpeed=1);

	//getters or accessors
	int getCollisionBoxHeight() const;
	int getCollisionBoxWidth() const;
	int getMovementSpeed() const;
};


#endif // COMMON_TO_ENTITIES_H


