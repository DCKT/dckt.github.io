open BsReactNative;

open Helpers;

let component = "Tag" |> ReasonReact.statelessComponent;

let styles =
  StyleSheet.create(
    Style.(
      {
        "tagRoot":
          style([
            paddingVertical(Pt(10.)),
            paddingHorizontal(Pt(15.)),
            borderRadius(4.),
            marginRight(Pt(10.)),
            marginBottom(Pt(10.)),
          ]),
        "tagText": style([color(String("#fff")), fontFamily("Ubuntu")]),
      }
    ),
  );

let getBgColor = (backgroundColor: option(string)) =>
  switch (backgroundColor) {
  | None => Style.String("#fff")
  | Some(value) => Style.String(value)
  };

let getTxtColor = (textColor: option(string)) =>
  switch (textColor) {
  | None => Style.String("#fff")
  | Some(value) => Style.String(value)
  };

let make =
    (
      ~value: string,
      ~backgroundColor: option(string),
      ~textColor: option(string),
      _children,
    ) => {
  ...component,
  render: _self => {
    let bgColorStyle =
      Style.style([Style.backgroundColor(getBgColor(backgroundColor))]);
    let txtColorStyle = Style.style([Style.color(getTxtColor(textColor))]);
    <View style=(StyleSheet.flatten([styles##tagRoot, bgColorStyle]))>
      <Text style=(StyleSheet.flatten([styles##tagText, txtColorStyle]))>
        (value |> text)
      </Text>
    </View>;
  },
};