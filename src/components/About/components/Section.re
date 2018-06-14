let component = "Section" |> ReasonReact.statelessComponent;

module Styles = {
  open Css;
  let container = style([padding2(~v=px(50), ~h=px(20))]);
  let darkContainer =
    style([
      background(hex("2c3e50")),
      color(hex("fff")),
      boxShadows([
        `shadow("inset 0px 3px 3px rgba(33,33,33,.7)"),
        `shadow("inset 0px -3px 3px rgba(33,33,33,.7)"),
      ]),
    ]);
};

let make = (~className: option(string)=?, ~dark: option(bool)=?, children) => {
  ...component,
  render: _self => {
    let customClassName =
      switch (className) {
      | None => Styles.container
      | Some(c) => Styles.container ++ " " ++ c
      };
    let classNameWithDarkTheme =
      switch (dark) {
      | None => customClassName
      | Some(_) => customClassName ++ " " ++ Styles.darkContainer
      };
    ReasonReact.createDomElement(
      "div",
      ~props={"className": classNameWithDarkTheme},
      children,
    );
  },
};