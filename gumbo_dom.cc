#include <iostream>
#include "gumbo_dom.h"

using namespace std;

void gumbo_traverse(GumboNode *root) {
  GumboVector *children;
  switch(root->type) {
  case GUMBO_NODE_WHITESPACE:
    cout << " ";
    break;

  case GUMBO_NODE_TEMPLATE:
    cout << "Its a TEMPLATE ";
    break;

  case GUMBO_NODE_ELEMENT:
    children = &root->v.element.children;
    for(int i = 0; i < children->length; ++i) {
      cout << typeid(children->data[i]).name();
      // gumbo_traverse(children->data[i]);
    }
    break;

  case GUMBO_NODE_TEXT:
    cout << root->v.text.text;
    break;

  default:
   // nothing
    break;
  }

}

// const char* initialize_gumbo_dom(GumboDOM *gumbo_dom, const char* html_string) {
//   GumboOutput* output = gumbo_parse(html_string);
//   gumbo_traverse(output->root);
//   gumbo_destroy_output(&kGumboDefaultOptions, output);
//   return "Hello";
// }

GumboDOM::GumboDOM() {
  html = "";
  initialize_gumbo_dom();
}

GumboDOM::GumboDOM(const char* html_string) {
    html = html_string;
}

void GumboDOM::initialize_gumbo_dom() {
    // unordered_map <string, int> m;
    // m["foo"] = 42;
    // cout << m["foo"] << endl;
}

const char* GumboDOM::getString(void) {
  return this->html;
}
