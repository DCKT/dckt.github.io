open BsReactNative;

let component = "Section" |> ReasonReact.statelessComponent;

let styles =
  StyleSheet.create(
    Style.(
      {
        "container":
          style([paddingVertical(Pt(80.)), paddingHorizontal(Pt(20.))]),
        "darkContainer": style([backgroundColor(String("#2c3e50"))]),
      }
    ),
  );

let make = (~dark: option(bool)=?, children) => {
  ...component,
  render: _self => {
    let style =
      switch (dark) {
      | None => styles##container
      | Some(_) =>
        StyleSheet.flatten([styles##container, styles##darkContainer])
      };
    <View style> ...children </View>;
  },
};