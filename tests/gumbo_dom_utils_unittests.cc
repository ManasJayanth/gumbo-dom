#include "gtest/gtest.h"
#include "../gumbo_dom_utils.h"

TEST(EncodeTextContentHTMLTest, EncodesHTMLEntities) {  
  std::string encoded_string;
  std::string test_string = "3 < 4";
  gumbo_dom_utils::encode_text_content_html(test_string, encoded_string);
  std::string expected_string = "3 &lt; 4";
  ASSERT_STREQ(encoded_string.c_str(), expected_string.c_str());
}

TEST(EncodeHTMLTest, EncodesHTMLEntities) {  
  std::string encoded_string;
  std::string test_string;
  std::string expected_string;

  test_string = "3 > 4";
  gumbo_dom_utils::encode_html(test_string, encoded_string);
  expected_string = "3 &gt; 4";
  ASSERT_STREQ(encoded_string.c_str(), expected_string.c_str());

  test_string = "Cox & Kings";
  gumbo_dom_utils::encode_html(test_string, encoded_string);
  expected_string = "Cox &amp; Kings";
  ASSERT_STREQ(encoded_string.c_str(), expected_string.c_str());

  test_string = "31 > 4";
  gumbo_dom_utils::encode_html(test_string, encoded_string);
  expected_string = "31 &gt; 4";
  ASSERT_STREQ(encoded_string.c_str(), expected_string.c_str());

  test_string = "3 < 4";
  gumbo_dom_utils::encode_html(test_string, encoded_string);
  expected_string = "3 &lt; 4";
  ASSERT_STREQ(encoded_string.c_str(), expected_string.c_str());

  test_string = "\"Hey You\"";
  gumbo_dom_utils::encode_html(test_string, encoded_string);
  expected_string = "&quot;Hey You&quot;";
  ASSERT_STREQ(encoded_string.c_str(), expected_string.c_str());
}

TEST(DecodeHTMLTest, EncodesHTMLEntities) {
  std::string decoded_string;
  std::string test_string;
  std::string expected_string;

  test_string = "3 &gt; 4";
  gumbo_dom_utils::decode_html(test_string, decoded_string);
  expected_string = "3 > 4";
  ASSERT_STREQ(decoded_string.c_str(), expected_string.c_str());

  test_string = "Cox &amp; Kings";
  gumbo_dom_utils::decode_html(test_string, decoded_string);
  expected_string = "Cox & Kings";
  ASSERT_STREQ(decoded_string.c_str(), expected_string.c_str());

  test_string = "31 &lt; 4";
  gumbo_dom_utils::decode_html(test_string, decoded_string);
  expected_string = "31 < 4";
  ASSERT_STREQ(decoded_string.c_str(), expected_string.c_str());

  test_string = "&quot;Hey You&quot;";
  gumbo_dom_utils::decode_html(test_string, decoded_string);
  expected_string = "\"Hey You\"";
  ASSERT_STREQ(decoded_string.c_str(), expected_string.c_str());
}
