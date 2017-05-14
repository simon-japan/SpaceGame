//
// Created by SJ Holland on 8/28/16.
//

#include "SpriteRendererFactory.h"
#include <memory>

using namespace std;

unique_ptr<GameObjectRenderer> SpriteRendererFactory::createCharacterRenderer(GameObject & subject) {

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
        Sprite * sprite = spriteRepository.getSprite("slug");
        renderer = std::make_unique<CharacterSpriteRenderer>(subject, *sprite, *sprite, *sprite, *sprite);
    }
    return renderer;
}

unique_ptr<GameObjectRenderer> SpriteRendererFactory::createTileRenderer(const Tile & subject) {

    // Look up which sprite to use, from the map of registered sprites,
    // based on the string provided by the Tile to identify its visual type.
    Sprite *sprite = spriteRepository.getSprite(subject.getName());

    unique_ptr<GameObjectRenderer> tileRenderer = make_unique<TileSpriteRenderer>(subject, *sprite);

    return tileRenderer;
}
