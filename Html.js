import React from 'react'
import { Helmet } from 'react-helmet'

export default ({ App, render }) => {
  // if needed, you can know if you are in development or in static rendering
  // const isDev = process.env.PHENOMIC_ENV === "development"
  const { Main, Head, State, Script, Style } = render(<App />)
  const helmet = Helmet.renderStatic()
  return (
    <html {...helmet.htmlAttributes.toComponent()}>
      <head>
        <meta charSet="utf8" />
        {helmet.meta.toComponent()}
        {helmet.title.toComponent()}
        {helmet.base.toComponent()}
        <Style />
        {helmet.link.toComponent()}
        {helmet.style.toComponent()}
        {helmet.script.toComponent()}
        {helmet.noscript.toComponent()}
      </head>
      <body {...helmet.bodyAttributes.toComponent()}>
        <Main />
        <State />
        <Script />
      </body>
    </html>
  )
}
