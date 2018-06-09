open BsReactNative;

open Helpers;

let component = "SocialsContainer" |> ReasonReact.statelessComponent;

let styles =
  StyleSheet.create(
    Style.(
      {
        "root":
          style([
            flex(1.0),
            flexDirection(Row),
            alignItems(Center),
            justifyContent(Center),
          ]),
      }
    ),
  );

let make = children => {
  ...component,
  render: _self => <View style=styles##root> children </View>,
};