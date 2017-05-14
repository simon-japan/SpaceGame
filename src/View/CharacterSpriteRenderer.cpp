//
// Created by SJ Holland on 8/27/16.
//

#include "CharacterSpriteRenderer.h"

void CharacterSpriteRenderer::render(SDL_Rect camera, SDL_Renderer *sdlRenderer) {
    SDL_Rect playerBox = character.getCollisionBox();
    Sprite * playerSprite = nullptr;
    Physical & physical = character.getPhysical();
    if (physical.getXVelocity() || physical.getYVelocity())
    {
        if (physical.getFacingDirection() == Direction::right) {
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
        if (physical.getFacingDirection() == Direction::right)
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
