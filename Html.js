// @flow

import React from 'react'
import { Helmet } from 'react-helmet'
import { AppRegistry } from 'react-native-web'

export default ({ App, render }) => {
  AppRegistry.registerComponent('App', () => App)
  const app = AppRegistry.getApplication('App')
  const { Main, State, Script, Style } = render(app.element)
  const helmet = Helmet.renderStatic()

  return (
    <html {...helmet.htmlAttributes.toComponent()}>
      <head>
        <meta charSet='utf8' />
        <link href='https://fonts.googleapis.com/css?family=Ubuntu:300,400,700' rel='stylesheet' />
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
