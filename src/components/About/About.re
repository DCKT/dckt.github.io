let component = "About" |> ReasonReact.statelessComponent;

let make = _children => {
  ...component,
  render: _self => <div> <Header /></div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));