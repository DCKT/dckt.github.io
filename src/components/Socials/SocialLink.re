open BsReactNative;

open Helpers;

let component = "SocialLink" |> ReasonReact.statelessComponent;

let styles =
  StyleSheet.create(Style.({"root": style([padding(Pt(10.))])}));

let make = (~href: string, ~imageSource: string, _children) => {
  ...component,
  render: _self =>
    <View style=styles##root>
      <a href>
        <Image
          source=(
            URI(
              Image.(
                imageURISource(~uri=imageSource, ~width=55., ~height=55., ())
              ),
            )
          )
        />
      </a>
    </View>,
};