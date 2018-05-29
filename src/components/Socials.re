let component = "Socials" |> ReasonReact.statelessComponent;

module Styles = {
  open Css;
  let root =
    style([
      display(`flex),
      flexDirection(row),
      alignItems(center),
      justifyContent(center),
    ]);
  let link =
    style([padding(px(10)), selector(":hover", [opacity(0.7)])]);
  let socialImage = style([width(px(55))]);
};

let make = _children => {
  ...component,
  render: _self =>
    <div className=Styles.root>
      <a href="https://twitter.com/DCK__" className=Styles.link>
        <img className=Styles.socialImage src="/images/socials/twitter.svg" />
      </a>
      <a href="https://twitter.com/DCK__" className=Styles.link>
        <img className=Styles.socialImage src="/images/socials/github.svg" />
      </a>
      <a href="https://twitter.com/DCK__" className=Styles.link>
        <img className=Styles.socialImage src="/images/socials/linkedin.svg" />
      </a>
    </div>,
};