module TextLinkNative = {
  [@bs.module "./TextLinkNative"]
  external link: ReasonReact.reactClass = "default";

  let make =
      (
        ~href: option(string)=?,
        ~style: option(BsReactNative.Style.t)=?,
        ~onPress,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=link,
      ~props={
        "href": Js.Nullable.fromOption(href),
        "style": Js.Nullable.fromOption(style),
        "onPress": onPress,
      },
      children,
    );
};

let component = ReasonReact.statelessComponent("TextLink");

let make = (~route: Routes.t, children) => {
  let href = Routes.toHref(route);
  let click = event => {
    ReactEvent.Mouse.preventDefault(event);
    ReasonReact.Router.push(href);
  };
  {
    ...component,
    render: _self =>
      <TextLinkNative href onPress=click> children </TextLinkNative>,
  };
};