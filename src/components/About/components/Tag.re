let component = "Tag" |> ReasonReact.statelessComponent;

module Styles = {
  open Css;
  let root = (bgColor: option(string)) => {
    let backgroundColor =
      switch (bgColor) {
      | None => background(`none)
      | Some(c) => unsafe("background", c)
      };
    style([
      display(`inlineBlock),
      verticalAlign(`middle),
      padding2(~v=px(10), ~h=px(15)),
      marginRight(px(8)),
      marginBottom(px(8)),
      borderRadius(px(4)),
      backgroundColor,
      color(hex("fff")),
    ]);
  };
};

let make = (~value: string, ~color: option(string)=?, _children) => {
  ...component,
  render: _self =>
    <div className=(Styles.root(color))> (value |> ReasonReact.string) </div>,
};