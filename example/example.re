let text = ReasonReact.string;

module Title = {
  let title = props =>
    Css.(style([fontSize(px(props##fontSize)), color(props##color)]));
  let make = (~fontSize, ~color, children) =>
    ReactFela.createComponent(
      ~rule=title,
      ~baseElement=`String("h1"),
      ~props={"fontSize": fontSize, "color": color},
      children,
    );
};

let styles = theme => {
  let card = () =>
    Css.(
      style([
        backgroundColor(white),
        boxShadow(~y=px(3), ~blur=px(5), rgba(0, 0, 0, 0.3)),
        padding(theme##basePadding),
      ])
    );
  {"card": card()};
};

let theme = {"textColor": Css.hex("333"), "basePadding": Css.px(15)};

Js.log(styles(theme));

module Page = {
  let component = ReasonReact.statelessComponent("Page");
  let make = (_) => {
    ...component,
    render: (_) =>
      <div
        style=(ReactDOMRe.Style.make(~color="#444444", ~fontSize="68px", ()))>
        <Title key="title" fontSize=20 color=Css.red> "I am red" </Title>
        <div
          style=(
            ReactDOMRe.Style.make(~color="#444444", ~fontSize="68px", ())
          )>
          ("App" |> text)
        </div>
      </div>,
  };
};

ReactDOMRe.renderToElementWithId(
  <ReactFela.Provider> <Page /> </ReactFela.Provider>,
  "app",
);