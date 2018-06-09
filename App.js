// @flow

import * as React from 'react'
import { AppRegistry } from 'react-native-web'
import { Router, Route, browserHistory } from 'react-router'
import { createApp, renderApp } from '@phenomic/preset-react-app/lib/client'
import { withPhenomicApi } from '@phenomic/preset-react-app/lib/es6/src/phenomicPresetReactApp.js'

import 'reset-css'
import './public/css/styles.css'

/**
 * Scenes
 */
import * as Home from './lib/es6/src/scenes/Home'
import * as Post from './lib/es6/src/scenes/Post'
import ErrorPage from './lib/es6/src/scenes/ErrorPage'

const routes = () => (
  <Router history={browserHistory}>
    <Route path='/' component={withPhenomicApi(Home.jsComponent, Home.queries)} />
    <Route path='/after/:after' component={withPhenomicApi(Home.jsComponent, Home.queries)} />
    <Route path='blog/*' component={withPhenomicApi(Post.jsComponent, Post.queries)} />
    <Route path='*' component={ErrorPage} />
    <Route path='404.html' component={ErrorPage} />
  </Router>
)

const render = (rootComponent, rootTag) => {
  AppRegistry.registerComponent('App', () => () => rootComponent)
  AppRegistry.runApplication('App', { rootTag })
}

export default createApp(routes, render)

if (module.hot) {
  module.hot.accept(() => renderApp(routes))
}
