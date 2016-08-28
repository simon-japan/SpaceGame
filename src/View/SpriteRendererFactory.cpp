//
// Created by SJ Holland on 8/28/16.
//

#include "SpriteRendererFactory.h"

GameObjectRenderer SpriteRendererFactory::createCharacterRenderer(Character & subject) {

    // Todo: determine which sprites to use based on the character's name (requires some more config)

    CharacterSpriteRenderer playerRenderer(subject,
                                     *spriteRepository.getSprite("spaceman_standing_left"),
                                     *spriteRepository.getSprite("spaceman_walking_left"),
                                     *spriteRepository.getSprite("spaceman_standing_right"),
                                     *spriteRepository.getSprite("spaceman_walking_right"));
    return playerRenderer;
}

GameObjectRenderer SpriteRendererFactory::createTileRenderer(Tile & subject) {

    // Look up which sprite to use, from the map of registered sprites,
    // based on the string provided by the Tile to identify its visual type.
    Sprite * sprite = spriteRepository.getSprite(subject.getName());

    return TileSpriteRenderer(subject, *sprite);
}
