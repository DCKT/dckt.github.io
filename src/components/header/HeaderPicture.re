open BsReactNative;

let component = "HeaderPicture" |> ReasonReact.statelessComponent;

let styles =
  StyleSheet.create(
    Style.(
      {
        "image":
          style([
            borderWidth(5.),
            borderColor(String("#fff")),
            borderRadius(300.),
          ]),
      }
    ),
  );

let make = _children => {
  ...component,
  render: _self =>
    <Image
      source=(
        URI(
          Image.(
            imageURISource(
              ~uri="/images/me.jpg",
              ~width=300.,
              ~height=300.,
              (),
            )
          ),
        )
      )
      style=styles##image
    />,
};