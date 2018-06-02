let nothing = ReasonReact.nullElement;

let text = ReasonReact.stringToElement;

let list = list => list |> Array.of_list |> ReasonReact.arrayToElement;

let nodeList = node => node##list |> Array.to_list;

let jsString = (text: string) => {js|text|js};

module Head = ReactHelmet;