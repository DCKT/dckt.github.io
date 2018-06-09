open BsReactNative;

let component = "Container" |> ReasonReact.statelessComponent;

let styles =
  StyleSheet.create(
    Style.(
      {
        "root":
          style([
            flex(1.),
            flexWrap(Wrap),
            maxWidth(Pt(960.)),
            alignItems(Center),
            margin(Auto),
          ]),
      }
    ),
  );

let make = children => {
  ...component,
  render: _self => <View style=styles##root> ...children </View>,
};