open BsReactNative;

open Helpers;

let component = "TagsList" |> ReasonReact.statelessComponent;

let styles =
  StyleSheet.create(
    Style.(
      {
        "root":
          style([
            flex(1.0),
            flexDirection(Row),
            justifyContent(Center),
            flexWrap(Wrap),
          ]),
      }
    ),
  );

let make =
    (
      ~tags: array(string),
      ~backgroundColor: option(string),
      ~textColor: option(string),
      _children,
    ) => {
  ...component,
  render: _self =>
    <View style=styles##root>
      (
        tags
        |> Array.mapi((i, tagValue) =>
             <Tag
               key=(string_of_int(i))
               backgroundColor
               textColor
               value=tagValue
             />
           )
        |> ReasonReact.arrayToElement
      )
    </View>,
};