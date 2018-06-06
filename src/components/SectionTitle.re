open BsReactNative;

open Helpers;

let component = "SectionTitle" |> ReasonReact.statelessComponent;

let styles =
  StyleSheet.create(
    Style.(
      {
        "root": style([marginVertical(Pt(50.))]),
        "title":
          style([
            fontSize(Float(40.)),
            fontWeight(`_700),
            textAlign(Center),
            fontFamily("Ubuntu"),
          ]),
      }
    ),
  );

let make = (~value: string, _children) => {
  ...component,
  render: _self =>
    <View style=styles##root>
      <Text style=styles##title> (value |> text) </Text>
    </View>,
};