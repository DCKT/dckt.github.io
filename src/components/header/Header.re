open BsReactNative;

open Helpers;

let component = "Header" |> ReasonReact.statelessComponent;

let styles =
  StyleSheet.create(
    Style.(
      {
        "root":
          style([
            flex(1.0),
            justifyContent(Center),
            alignItems(Center),
            height(Pt(600.)),
            paddingVertical(Pt(100.)),
            backgroundColor(String("#333")),
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