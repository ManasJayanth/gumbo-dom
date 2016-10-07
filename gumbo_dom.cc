#include <iostream>
#include "gumbo_dom.h"

void gumbo_traverse(GumboNode *root) {
  GumboVector *children;
  switch (root->type) {
  case GUMBO_NODE_WHITESPACE:
    break;

  case GUMBO_NODE_TEMPLATE:
    break;

  case GUMBO_NODE_ELEMENT:
    children = &root->v.element.children;
    for (int i = 0; i < children->length; ++i) {
      // cout << typeid(children->data[i]).name();
      // gumbo_traverse(children->data[i]);
    }
    break;

  case GUMBO_NODE_TEXT:
    // cout << root->v.text.text;
    break;

  default:
    // nothing
    break;
  }
}

const char* initialize_gumbo_dom(GumboDOM *gumbo_dom, const char* html_string) {
  GumboOutput* output = gumbo_parse(html_string);
  gumbo_traverse(output->root);
  gumbo_destroy_output(&kGumboDefaultOptions, output);
  return "Hello";
}

GumboDOM::GumboDOM() {
  html = string("");

  std::map<std::string, std::string> styleMap;
  styleMap["alignmentBaseline"] = "alignment-baseline";
  styleMap["background"] = "background";
  styleMap["backgroundAttachment"] = "background-attachment";
  styleMap["backgroundClip"] = "background-clip";
  styleMap["backgroundColor"] = "background-color";
  styleMap["backgroundImage"] = "background-image";
  styleMap["backgroundOrigin"] = "background-origin";
  styleMap["backgroundPosition"] = "background-position";
  styleMap["backgroundPositionX"] = "background-position-x";
  styleMap["backgroundPositionY"] = "background-position-y";
  styleMap["backgroundRepeat"] = "background-repeat";
  styleMap["backgroundRepeatX"] = "background-repeat-x";
  styleMap["backgroundRepeatY"] = "background-repeat-y";
  styleMap["backgroundSize"] = "background-size";
  styleMap["baselineShift"] = "baseline-shift";
  styleMap["border"] = "border";
  styleMap["borderBottom"] = "border-bottom";
  styleMap["borderBottomColor"] = "border-bottom-color";
  styleMap["borderBottomLeftRadius"] = "border-bottom-left-radius";
  styleMap["borderBottomRightRadius"] = "border-bottom-right-radius";
  styleMap["borderBottomStyle"] = "border-bottom-style";
  styleMap["borderBottomWidth"] = "border-bottom-width";
  styleMap["borderCollapse"] = "border-collapse";
  styleMap["borderColor"] = "border-color";
  styleMap["borderImage"] = "border-image";
  styleMap["borderImageOutset"] = "border-image-outset";
  styleMap["borderImageRepeat"] = "border-image-repeat";
  styleMap["borderImageSlice"] = "border-image-slice";
  styleMap["borderImageSource"] = "border-image-source";
  styleMap["borderImageWidth"] = "border-image-width";
  styleMap["borderLeft"] = "border-left";
  styleMap["borderLeftColor"] = "border-left-color";
  styleMap["borderLeftStyle"] = "border-left-style";
  styleMap["borderLeftWidth"] = "border-left-width";
  styleMap["borderRadius"] = "border-radius";
  styleMap["borderRight"] = "border-right";
  styleMap["borderRightColor"] = "border-right-color";
  styleMap["borderRightStyle"] = "border-right-style";
  styleMap["borderRightWidth"] = "border-right-width";
  styleMap["borderSpacing"] = "border-spacing";
  styleMap["borderStyle"] = "border-style";
  styleMap["borderTop"] = "border-top";
  styleMap["borderTopColor"] = "border-top-color";
  styleMap["borderTopLeftRadius"] = "border-top-left-radius";
  styleMap["borderTopRightRadius"] = "border-top-right-radius";
  styleMap["borderTopStyle"] = "border-top-style";
  styleMap["borderTopWidth"] = "border-top-width";
  styleMap["borderWidth"] = "border-width";
  styleMap["bottom"] = "bottom";
  styleMap["boxShadow"] = "box-shadow";
  styleMap["boxSizing"] = "box-sizing";
  styleMap["captionSide"] = "caption-side";
  styleMap["clear"] = "clear";
  styleMap["clip"] = "clip";
  styleMap["clipPath"] = "clip-path";
  styleMap["clipRule"] = "clip-rule";
  styleMap["color"] = "color";
  styleMap["colorInterpolation"] = "color-interpolation";
  styleMap["colorInterpolationFilters"] = "color-interpolation-filters";
  styleMap["colorProfile"] = "color-profile";
  styleMap["colorRendering"] = "color-rendering";
  styleMap["content"] = "content";
  styleMap["counterIncrement"] = "counter-increment";
  styleMap["counterReset"] = "counter-reset";
  styleMap["cursor"] = "cursor";
  styleMap["direction"] = "direction";
  styleMap["display"] = "display";
  styleMap["dominantBaseline"] = "dominant-baseline";
  styleMap["emptyCells"] = "empty-cells";
  styleMap["enableBackground"] = "enable-background";
  styleMap["fill"] = "fill";
  styleMap["fillOpacity"] = "fill-opacity";
  styleMap["fillRule"] = "fill-rule";
  styleMap["filter"] = "filter";
  styleMap["cssFloat"] = "float";
  styleMap["floodColor"] = "flood-color";
  styleMap["floodOpacity"] = "flood-opacity";
  styleMap["font"] = "font";
  styleMap["fontFamily"] = "font-family";
  styleMap["fontSize"] = "font-size";
  styleMap["fontStretch"] = "font-stretch";
  styleMap["fontStyle"] = "font-style";
  styleMap["fontVariant"] = "font-variant";
  styleMap["fontWeight"] = "font-weight";
  styleMap["glyphOrientationHorizontal"] = "glyph-orientation-horizontal";
  styleMap["glyphOrientationVertical"] = "glyph-orientation-vertical";
  styleMap["height"] = "height";
  styleMap["imageRendering"] = "image-rendering";
  styleMap["kerning"] = "kerning";
  styleMap["left"] = "left";
  styleMap["letterSpacing"] = "letter-spacing";
  styleMap["lightingColor"] = "lighting-color";
  styleMap["lineHeight"] = "line-height";
  styleMap["listStyle"] = "list-style";
  styleMap["listStyleImage"] = "list-style-image";
  styleMap["listStylePosition"] = "list-style-position";
  styleMap["listStyleType"] = "list-style-type";
  styleMap["margin"] = "margin";
  styleMap["marginBottom"] = "margin-bottom";
  styleMap["marginLeft"] = "margin-left";
  styleMap["marginRight"] = "margin-right";
  styleMap["marginTop"] = "margin-top";
  styleMap["marker"] = "marker";
  styleMap["markerEnd"] = "marker-end";
  styleMap["markerMid"] = "marker-mid";
  styleMap["markerStart"] = "marker-start";
  styleMap["mask"] = "mask";
  styleMap["maxHeight"] = "max-height";
  styleMap["maxWidth"] = "max-width";
  styleMap["minHeight"] = "min-height";
  styleMap["minWidth"] = "min-width";
  styleMap["opacity"] = "opacity";
  styleMap["orphans"] = "orphans";
  styleMap["outline"] = "outline";
  styleMap["outlineColor"] = "outline-color";
  styleMap["outlineOffset"] = "outline-offset";
  styleMap["outlineStyle"] = "outline-style";
  styleMap["outlineWidth"] = "outline-width";
  styleMap["overflow"] = "overflow";
  styleMap["overflowX"] = "overflow-x";
  styleMap["overflowY"] = "overflow-y";
  styleMap["padding"] = "padding";
  styleMap["paddingBottom"] = "padding-bottom";
  styleMap["paddingLeft"] = "padding-left";
  styleMap["paddingRight"] = "padding-right";
  styleMap["paddingTop"] = "padding-top";
  styleMap["page"] = "page";
  styleMap["pageBreakAfter"] = "page-break-after";
  styleMap["pageBreakBefore"] = "page-break-before";
  styleMap["pageBreakInside"] = "page-break-inside";
  styleMap["pointerEvents"] = "pointer-events";
  styleMap["position"] = "position";
  styleMap["quotes"] = "quotes";
  styleMap["resize"] = "resize";
  styleMap["right"] = "right";
  styleMap["shapeRendering"] = "shape-rendering";
  styleMap["size"] = "size";
  styleMap["speak"] = "speak";
  styleMap["src"] = "src";
  styleMap["stopColor"] = "stop-color";
  styleMap["stopOpacity"] = "stop-opacity";
  styleMap["stroke"] = "stroke";
  styleMap["strokeDasharray"] = "stroke-dasharray";
  styleMap["strokeDashoffset"] = "stroke-dashoffset";
  styleMap["strokeLinecap"] = "stroke-linecap";
  styleMap["strokeLinejoin"] = "stroke-linejoin";
  styleMap["strokeMiterlimit"] = "stroke-miterlimit";
  styleMap["strokeOpacity"] = "stroke-opacity";
  styleMap["strokeWidth"] = "stroke-width";
  styleMap["tableLayout"] = "table-layout";
  styleMap["textAlign"] = "text-align";
  styleMap["textAnchor"] = "text-anchor";
  styleMap["textDecoration"] = "text-decoration";
  styleMap["textIndent"] = "text-indent";
  styleMap["textLineThrough"] = "text-line-through";
  styleMap["textLineThroughColor"] = "text-line-through-color";
  styleMap["textLineThroughMode"] = "text-line-through-mode";
  styleMap["textLineThroughStyle"] = "text-line-through-style";
  styleMap["textLineThroughWidth"] = "text-line-through-width";
  styleMap["textOverflow"] = "text-overflow";
  styleMap["textOverline"] = "text-overline";
  styleMap["textOverlineColor"] = "text-overline-color";
  styleMap["textOverlineMode"] = "text-overline-mode";
  styleMap["textOverlineStyle"] = "text-overline-style";
  styleMap["textOverlineWidth"] = "text-overline-width";
  styleMap["textRendering"] = "text-rendering";
  styleMap["textShadow"] = "text-shadow";
  styleMap["textTransform"] = "text-transform";
  styleMap["textUnderline"] = "text-underline";
  styleMap["textUnderlineColor"] = "text-underline-color";
  styleMap["textUnderlineMode"] = "text-underline-mode";
  styleMap["textUnderlineStyle"] = "text-underline-style";
  styleMap["textUnderlineWidth"] = "text-underline-width";
  styleMap["top"] = "top";
  styleMap["unicodeBidi"] = "unicode-bidi";
  styleMap["unicodeRange"] = "unicode-range";
  styleMap["vectorEffect"] = "vector-effect";
  styleMap["verticalAlign"] = "vertical-align";
  styleMap["visibility"] = "visibility";
  styleMap["whiteSpace"] = "white-space";
  styleMap["widows"] = "widows";
  styleMap["width"] = "width";
  styleMap["wordBreak"] = "word-break";
  styleMap["wordSpacing"] = "word-spacing";
  styleMap["wordWrap"] = "word-wrap";
  styleMap["writingMode"] = "writing-mode";
  styleMap["zIndex"] = "z-index";
  styleMap["zoom"] = "zoom";

  // Elements that can be self-closing
  std::map<std::string, std::string> voidElems;
  voidElems["area"] = true;
  voidElems["base"] = true;
  voidElems["br"] = true;
  voidElems["col"] = true;
  voidElems["command"] = true;
  voidElems["embed"] = true;
  voidElems["hr"] = true;
  voidElems["img"] = true;
  voidElems["input"] = true;
  voidElems["link"] = true;
  voidElems["meta"] = true;
  voidElems["param"] = true;
  voidElems["source"] = true;
  voidElems["wbr"] = true;
};

explicit GumboDOM::GumboDOM(const char* html_string) {
  html = html_string;
}

const char* GumboDOM::getString(void) {
  return this->html.c_str();
}
