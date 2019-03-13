open BsReactNative;

let animatedValue = Animated.Value.create(0.0);

let styles =
  StyleSheet.create(
    Style.{
      "wrapper":
        style([
          flex(1.),
          flexDirection(Column),
          backgroundColor(String("#6698FF")),
        ]),
      "test": style([opacity(Animated(animatedValue))]),
      "text":
        style([
          color(String("#fff")),
          fontSize(Float(30.)),
          fontWeight(`_500),
          marginLeft(Pt(15.)),
        ]),
    },
  );

let component = "Home" |> ReasonReact.statelessComponent;

let make = _children => {
  ...component,
  didMount: _self =>
    Animated.start(
      Animated.timing(
        ~value=animatedValue,
        ~toValue=`raw(1.0),
        ~duration=1000.0,
        (),
      ),
      ~callback=_didFinish => (),
      (),
    ),
  render: _self =>
    <View style=styles##wrapper>
      <Animated.View style=styles##test>
        <Text style=styles##text value="Reason is awesome!" />
      </Animated.View>
    </View>,
};