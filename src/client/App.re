/* App is the actual entry point for the application. It matches on the route prop to determine which
   sub-component to render */
open BsReactNative;

let styles =
  StyleSheet.create(
    Style.{
      "navBar":
        style([
          flexDirection(Row),
          backgroundColor(String("#f1f1f1")),
          paddingVertical(Pt(8.)),
          paddingHorizontal(Pt(16.)),
        ]),

      "link":
        style([
          paddingVertical(Pt(4.)),
          paddingHorizontal(Pt(8.)),
          marginRight(Pt(8.)),
        ]),
    },
  );

let component = ReasonReact.statelessComponent("App");

let make = (~route: Routes.t, _children) => {
  ...component,

  render: _self => {
    switch (route) {
    | Home => <Home />
    | Greet(greeting) => <Greet ?greeting />
    | NotFound =>
      <View>
        <Text> {"404 - Route Not Found :(" |> ReasonReact.string} </Text>
      </View>
    };
  },
  // </View>
  //   </View>
  //     </TextLink>
  //       {ReasonReact.string("Greet")}
  //     <TextLink route={Greet(Some("Hello!"))}>
  //   <View style=styles##link>
  //   </View>
  //     <TextLink route=Home> {ReasonReact.string("Home")} </TextLink>
  //   <View style=styles##link>
  // <View style=styles##navBar>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~route=jsProps##route, [||])
  );