//
// Created by SJ Holland on 8/27/16.
//

#include "CharacterSpriteRenderer.h"
#include "../Model/Geometry.h"

void CharacterSpriteRenderer::render(SDL_Rect camera, SDL_Renderer *sdlRenderer) {

    SDL_Rect box = character.getCollisionBox();

    // Only render the object if it's in-camera
    if (Geometry::checkCollision(box, camera)) {
        Sprite *sprite = nullptr;
        PhysicalProperties & physical = character.getPhysicalProperties();
        VisualProperties & visualProperties = character.getVisualProperties();

        if (physical.getXVelocity() || physical.getYVelocity()) {
            if (physical.getFacingDirection() == Direction::right) {
                sprite = &walkingRightSprite;
            } else {
                sprite = &walkingLeftSprite;
            }
        } else {
            animationState = 0;
            if (physical.getFacingDirection() == Direction::right) {
                sprite = &standingRightSprite;
            } else {
                sprite = &standingLeftSprite;
            }

        }

        int renderWidth = visualProperties.getRenderWidth();
        int renderHeight = visualProperties.getRenderHeight();
        if (renderHeight && renderWidth)
        {
            SDL_Rect target;
            target.x = box.x - camera.x;
            target.y = box.y - camera.y;
            target.w = renderWidth;
            target.h = renderHeight;

            animationState = sprite->render(target, animationState, sdlRenderer);
        }
        else
        {
            animationState = sprite->render(box.x - camera.x, box.y - camera.y, animationState, sdlRenderer);
        }
    }

}


