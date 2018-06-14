let component = "About" |> ReasonReact.statelessComponent;

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <Header />
      <Section> <SectionTitle value="Hello" /> </Section>
    </div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));