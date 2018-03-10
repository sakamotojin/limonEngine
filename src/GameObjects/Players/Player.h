//
// Created by engin on 15.02.2018.
//

#ifndef LIMONENGINE_PLAYER_H
#define LIMONENGINE_PLAYER_H

#include "../GameObject.h"
#include <glm/glm.hpp>
#include <string>

class btDiscreteDynamicsWorld;

class Player : public GameObject {
public:
    enum moveDirections {
        NONE, FORWARD, BACKWARD, LEFT, RIGHT, LEFT_FORWARD, RIGHT_FORWARD, LEFT_BACKWARD, RIGHT_BACKWARD, UP
    };

    virtual void move(moveDirections) = 0;

    virtual void rotate(float xChange, float yChange) = 0;

    virtual glm::vec3 getPosition() const = 0;

    /**
     * This method should be used when player type changes, like from physical to free fly etc.
     *
     * @param position
     * @param lookDirection
     */
    virtual void setPositionAndRotation(const glm::vec3& position, const glm::vec3 lookDirection) = 0;

    virtual void registerToPhysicalWorld(btDiscreteDynamicsWorld* world, const glm::vec3& worldAABBMin, const glm::vec3& worldAABBMax) = 0;

    virtual ~Player() {}

    virtual void processPhysicsWorld(const btDiscreteDynamicsWorld *world) = 0;

    virtual glm::vec3 getLookDirection() const = 0;

    virtual void getWhereCameraLooks(glm::vec3 &fromPosition, glm::vec3 &lookDirection) const = 0;

    /************Game Object methods **************/
    ObjectTypes getTypeID() const {
        return GameObject::PLAYER;
    };

    std::string getName() const {
        return "Player";//Players doesn't have specific names
    };
    /************Game Object methods **************/
};


#endif //LIMONENGINE_PLAYER_H