//
// Created by SJ Holland on 8/28/16.
//

#include "GameObjectRendererFactory.h"
#include "CharacterSpriteRenderer.h"
#include <memory>

using namespace std;

unique_ptr<GameObjectRenderer> GameObjectRendererFactory::createGameObjectRenderer(GameObject & subject) {

    // Todo: make determining which sprites to use based on the character's name less dumb (requires some more config)

    unique_ptr<GameObjectRenderer> renderer;

    if (!subject.getName().compare("Player"))
    {
        renderer = std::make_unique<CharacterSpriteRenderer>(subject,
                                                             *spriteRepository.getSprite(
                                                                     "spaceman_standing_left"),
                                                             *spriteRepository.getSprite("spaceman_walking_left"),
                                                             *spriteRepository.getSprite(
                                                                     "spaceman_standing_right"),
                                                             *spriteRepository.getSprite(
                                                                     "spaceman_walking_right"));
    }
    else if (!subject.getName().compare("bullet"))
    {
        Sprite * sprite = spriteRepository.getSprite("bullet_blue");
        renderer = std::make_unique<CharacterSpriteRenderer>(subject, *sprite, *sprite, *sprite, *sprite);
    }
    else
    {
        // Default sprite
        Sprite * sprite = spriteRepository.getSprite(subject.getVisualProperties().getSpriteName());
        renderer = std::make_unique<CharacterSpriteRenderer>(subject, *sprite, *sprite, *sprite, *sprite);
    }
    return renderer;
}

