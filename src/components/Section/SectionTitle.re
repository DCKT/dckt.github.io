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

let make = (~value: string, ~textColor: option(string)=?, _children) => {
  ...component,
  render: _self => {
    let textColor =
      switch (textColor) {
      | None => Style.style([])
      | Some(c) => Style.(style([color(String(c))]))
      };
    <View style=styles##root>
      <Text style=(Style.flatten([|styles##title, textColor|]))>
        (value |> text)
      </Text>
    </View>;
  },
};