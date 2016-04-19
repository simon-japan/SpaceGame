//
// Created by SJ Holland on 4/9/16.
//

#include <gtest/gtest.h>
#include "../../src/Model/Tile.h"

TEST(model_check, test_eq) {
    Tile tile (1,2,"Simon", false);
    EXPECT_EQ(0, strcmp("Simon", tile.getType().c_str()));
}