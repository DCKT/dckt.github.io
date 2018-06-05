open BsReactNative;

open Helpers;

let component = "HeaderTitle" |> ReasonReact.statelessComponent;

let styles =
  StyleSheet.create(
    Style.(
      {
        "root": style([flex(1.0), marginVertical(Pt(20.))]),
        "title":
          style([
            fontSize(Float(32.)),
            color(String("#fff")),
            textAlign(Center),
            fontWeight(`_300),
          ]),
        "subtitle":
          style([
            fontWeight(`_600),
            marginVertical(Pt(10.)),
            fontStyle(Italic),
            color(String("#fff")),
          ]),
      }
    ),
  );

let make = _children => {
  ...component,
  render: _self =>
    <View style=styles##root>
      <Text style=styles##title> ("Thomas Deconinck" |> text) </Text>
      <Text style=(StyleSheet.flatten([styles##title, styles##subtitle]))>
        ({js|Développeur JavaScript|js} |> text)
      </Text>
    </View>,
};