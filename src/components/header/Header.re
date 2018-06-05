open BsReactNative;

open Helpers;

let component = "Header" |> ReasonReact.statelessComponent;

module Styles = {
  open Css;
  let root =
    style([
      display(`flex),
      justifyContent(center),
      alignItems(center),
      height(pct(98.5)),
      backgroundImage(url("/images/header.jpg")),
      backgroundSize(cover),
      backgroundPosition(pct(50.), pct(50.)),
      selector(
        "&:before",
        [
          unsafe("content", " "),
          display(block),
          position(`absolute),
          top(px(0)),
          left(px(0)),
          width(pct(100.)),
          height(pct(100.)),
          backgroundColor(rgba(33, 33, 33, 0.5)),
        ],
      ),
    ]);
  let headerContent = style([zIndex(1)]);
};

let styles =
  StyleSheet.create(
    Style.(
      {
        "root":
          style([
            flex(1.0),
            justifyContent(Center),
            alignItems(Center),
            height(Pct(98.5)),
            paddingVertical(Pt(100.)),
          ]),
      }
    ),
  );

let make = _children => {
  ...component,
  render: _self =>
    <ImageBackground
      style=styles##root
      source=(URI(Image.(imageURISource(~uri="/images/header.jpg", ()))))>
      <HeaderPicture />
      <HeaderTitle />
    </ImageBackground>,
};