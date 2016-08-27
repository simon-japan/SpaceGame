//
// Created by SJ Holland on 8/27/16.
//

#include "CharacterRenderer.h"

// todo: some logic to control animation state

void CharacterRenderer::render(Character character, SDL_Rect camera, SDL_Renderer *sdlRenderer) {
    SDL_Rect playerBox = character.getCollisionBox();
    Sprite * playerSprite = nullptr;
    if (character.getXVelocity() || character.getYVelocity())
    {
        if (character.getDirection() == Direction::right) {
            playerSprite = &walkingRightSprite;
        }
        else
        {
            playerSprite = &walkingLeftSprite;
        }
    }
    else
    {
        animationState = 0;
        if (character.getDirection() == Direction::right)
        {
            playerSprite = &standingRightSprite;
        }
        else
        {
            playerSprite = &standingLeftSprite;
        }

    }
    animationState = playerSprite->render(playerBox.x - camera.x, playerBox.y - camera.y, animationState, sdlRenderer);

}
