#include "CommonToEntities.h"

//Constructor which uses initializers list.
//It also acts as a default constructor as deafult values for all the variables are present.
CommonToEntities::CommonToEntities(int h, int w, int m): collisionBoxHeight(h), collisionBoxWidth(w), movementSpeed(m)
{
    
}


//getters or accessors
int CommonToEntities::getCollisionBoxHeight() const
{
    return this->collisionBoxHeight;
}

int CommonToEntities::getCollisionBoxWidth() const
{
    return this->collisionBoxWidth;
}

int CommonToEntities::getMovementSpeed() const
{
    return this->movementSpeed;
}
