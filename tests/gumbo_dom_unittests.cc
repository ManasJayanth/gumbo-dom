#include "gtest/gtest.h"
#include "../headers.h"

TEST(CleanHTMLTest, ExtractsRelevantArticle) {
  EXPECT_STREQ(clean_html(""), "");
}
